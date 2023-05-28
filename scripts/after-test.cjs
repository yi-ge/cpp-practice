const fs = require('fs')
const path = require('path')
const { spawnSync } = require('child_process');
const xml2js = require('xml2js');

const gtestLogFilePath = path.join(process.cwd(), 'build/gtest.log')
if (!fs.existsSync(gtestLogFilePath)) {
  console.log('执行单元测试失败！')
  process.exit(1)
}

// 打印测试结果
const output = fs.readFileSync(gtestLogFilePath, 'utf-8')
console.log(output)

// 判断是否存在"PASSED"字符串，如果有，说明测试通过，进行测试覆盖率统计
if (output.includes('PASSED')) {
  // 执行../build/cpp-practice" "--gtest_list_tests" "--gtest_output=xml:../build/cpp-practice.testListCache.xml" 2>&1
  // 得到测试用例列表
  const cmd = path.join(process.cwd(), 'build', 'cpp-practice' + (process.platform === 'win32' ? '.exe' : ''))
  const cwd = path.join(process.cwd(), 'build')
  const args = '--gtest_list_tests --gtest_output=xml:' + path.join(cwd, 'cpp-practice.testListCache.xml')
  // 过程不输出到控制台
  const executeHidden = spawnSync(cmd, args.split(' '), {
    cwd,
    env: process.env,
    stdio: 'ignore',
  });

  // 如果执行命令返回非零状态，则退出
  if (executeHidden.status !== 0) {
    console.log('报错了，请检查上面的错误信息。')
    process.exit(executeHidden.status);
  }

  // 获取xml文件内容
  const testListXML = fs.readFileSync(path.join(process.cwd(), 'build/cpp-practice.testListCache.xml'), 'utf-8')
  if (!testListXML) {
    console.log('测试用例列表为空。')
    process.exit(1)
  }

  // 读取../build/command.txt文件，得到测试用例执行命令
  const commandTxt = fs.readFileSync(path.join(process.cwd(), 'build/command.txt'), 'utf-8')
  if (!commandTxt) {
    console.log('测试用例执行命令为空。')
    process.exit(1)
  }

  // 获取最新的一行
  const commandList = commandTxt.split('\n')
  let lineIndex = commandList.length - 2
  let commandLine = commandList[lineIndex]
  if (!commandLine) {
    console.log('测试用例执行命令为空。')
    process.exit(1)
  }

  while (!commandLine.includes('gtest_filter')) {
    commandLine = commandList[--lineIndex]
    if (!commandLine) {
      console.log('测试用例执行命令未找到。')
      process.exit(1)
    }
  }

  // 内容示例：Time: 2023-05-27 18:35:25, Command: "/Users/yige/Project/cpp-practice/build/cpp-practice" "--gtest_color=yes" "--gtest_filter=子串能表示从1到N数字的二进制串.queryString:检查二进制字符串字段.checkOnesSegment:按字典序排在最后的子串.lastSubstring:段式回文.longestDecomposition" "--gtest_also_run_disabled_tests" 2>&1
  // 得到Command
  const command = commandLine.split('Command: ')[1]
  if (!command) {
    console.log('测试用例执行命令异常。')
    process.exit(1)
  }

  // 解析--gtest_filter=参数，得到所有测试用例的名称
  const gtestFilterRegex = /--gtest_filter=(.*?)["\s]/; // 兼容Windows
  const gtestFilterMatch = command.match(gtestFilterRegex);

  if (!gtestFilterMatch || gtestFilterMatch.length < 1) {
    console.log('解析--gtest_filter=参数失败。');
    process.exit(1);
  }

  const gtestFilterValue = gtestFilterMatch[1];
  const testCaseNames = gtestFilterValue.split(':').filter((name) => name.length > 0);

  // console.log('测试用例名称:', testCaseNames);

  // 提取所有测试用例的名称和文件路径
  const testFilePaths = new Set();

  // 解析xml文件，得到测试用例列表
  xml2js.parseString(testListXML, (err, result) => {
    if (err) {
      console.log('解析XML文件失败。');
      process.exit(1);
    }

    const testsuites = result.testsuites.testsuite;
    testsuites.forEach((testsuite) => {
      testsuite.testcase.forEach((testcase) => {
        const testNameWithSuite = `${testsuite.$.name}.${testcase.$.name}`;
        // console.log(testNameWithSuite)
        // console.log(testCaseNames)
        if (testCaseNames.includes(testNameWithSuite)) {
          testFilePaths.add(testcase.$.file);
        }
      });
    });

    // 去重后的文件路径
    const uniqueTestFilePaths = [...new Set([...testFilePaths])];

    const keepOnlyPaths = [];

    // 读取所有文件里面#include <array/adding_two_negabinary_numbers.cpp>信息，得到所有测试用例的文件路径，去重
    // 只考虑#include <array或#include "array的情况
    // array可能为array、graphs、lib、list、map、math、other、search、sort、stack、string、tree
    const includeRegex = /#include\s+["<](array|graphs|lib|list|map|math|other|search|sort|stack|string|tree)\/(.*?)\.(cpp|hpp)/g;
    uniqueTestFilePaths.map((filePath) => {
      // 移除filePath中test之前的路径
      const index = filePath.indexOf('test');
      if (index > 0) {
        const testFilePath = filePath.substring(index)
        // keepOnlyPaths.push(testFilePath);
        if (testFilePath.includes('lib/')) {
          if (!testFilePath.includes('utils_test.cpp')) {
            keepOnlyPaths.push(testFilePath.replace('test/', 'src/').replace('_test.cpp', '.cpp'));
          }
        } else {
          const fileContent = fs.readFileSync(filePath, 'utf-8')
          const match = fileContent.match(includeRegex);
          if (match) {
            // 得到里面从<或"之后到结尾的路径
            let srcPath = match[0].split('"')[1] ? match[0].split('"')[1] : match[0].split('<')[1];
            // 移除末尾.cpp或.hpp
            srcPath = srcPath.substring(0, srcPath.length - 4);
            keepOnlyPaths.push('*' + srcPath + '*');
          }
        }
      }
    });

    // OnlyTest 遍历src和test目录，得到所有文件路径，找出不在keepOnlyPaths里面的文件路径或者不存在的文件路径，打印出来
    // const glob = require('glob');
    // const srcFiles = glob.sync('src/**/*.cpp');
    // const testFiles = glob.sync('test/**/*.cpp');
    // const allFiles = [...srcFiles, ...testFiles];
    // const notInKeepOnlyPaths = allFiles.filter((filePath) => !keepOnlyPaths.includes(filePath));
    // const notExistFiles = keepOnlyPaths.filter((filePath) => !allFiles.includes(filePath));
    // console.log('不在keepOnlyPaths里面的文件路径：')
    // console.log(notInKeepOnlyPaths.join('\n'))
    // console.log('不存在的文件路径：')
    // console.log(notExistFiles.join('\n'))
    // console.log('keepOnlyPaths里面的文件路径：')
    // console.log(keepOnlyPaths.join('\n'))

    // 组合成为globs格式的路径，并添加 --keep-only 参数
    const keepOnlyArgs = keepOnlyPaths.map((path) => `--keep-only ${path}`).join(' ');

    // 运行grcov命令
    // let grcovCmd = `grcov . -s . --binary-path ./build/ -t html --llvm --guess-directory-when-missing --ignore test/* --branch ${keepOnlyArgs} -o ./coverage/`;
    let grcovCmd = `grcov . -s . --binary-path ./build/ -t lcov --llvm --guess-directory-when-missing --ignore test/* --branch ${keepOnlyArgs} -o ./coverage/lcov.info`;

    // 移除字符串前几个字符
    grcovCmd = grcovCmd.substring(grcovCmd.indexOf('grcov') + 6);

    // 转为数组
    grcovCmd = grcovCmd.split(' ')

    // 根据系统类型，设置llvmPath
    let llvmPath = '/usr/local/opt/llvm/bin/';

    if (process.platform === 'win32') {
      llvmPath = 'C:\\Program Files\\LLVM\\bin\\';
    } else if (process.platform === 'darwin') {
      llvmPath = '/opt/homebrew/opt/llvm/bin/';
    } else {
      // 执行which llvm-profdata命令，获取llvmPath
      const which = spawnSync('which', ['llvm-profdata'], {
        cwd: path.join(process.cwd()), // 当前工作目录
        env: process.env,  // 附加当前操作系统的环境变量
        stdio: 'pipe',  // 混合标准输出和错误输出
      });
      if (which.status === 0) {
        llvmPath = which.stdout.toString().replace('llvm-profdata', '');
      }
    }

    grcovCmd.push('--llvm-path')
    grcovCmd.push(llvmPath)

    // 在 Windows 上，二进制文件的扩展名是 .exe
    // 在其他系统上，扩展名是空字符串
    const extension = process.platform === 'win32' ? '.exe' : '';

    // 文件路径
    const output = `grcov${extension}`;
    const grcovFilePath = path.join(process.cwd(), 'scripts', output);

    // 如果coverage目录不存在，则创建
    const dir = path.join(process.cwd(), 'coverage')
    if (!fs.existsSync(dir)) {
      fs.mkdirSync(dir)
    }

    // 如果已经存在覆盖率文件，则删除
    if (fs.existsSync(path.join(process.cwd(), 'coverage', 'lcov.info'))) {
      fs.unlinkSync(path.join(process.cwd(), 'coverage', 'lcov.info'))
    }

    // 删除已存在的多余的default.profraw文件
    // const profrawFilePath = path.join(process.cwd(), 'default.profraw')
    // if (fs.existsSync(profrawFilePath)) {
    //   fs.unlinkSync(profrawFilePath)
    // }

    // 执行覆盖率文件生成命令
    const execute = spawnSync(grcovFilePath, grcovCmd, {
      cwd: path.join(process.cwd()), // 当前工作目录
      env: process.env,  // 附加当前操作系统的环境变量
      stdio: 'inherit',  // 混合标准输出和错误输出
    });

    // 如果执行命令返回非零状态，则退出
    if (execute.status !== 0) {
      console.log('报错了，请检查上面的错误信息。')
      process.exit(execute.status);
    } else {
      console.log('已生成测试覆盖率。')
    }
  });

  process.exit(0)
} else {
  process.exit(1)
}