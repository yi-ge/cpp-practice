const { spawnSync } = require('child_process');
const path = require('path');
const fs = require('fs')

// 在 Windows 上，二进制文件的扩展名是 .exe
// 在其他系统上，扩展名是空字符串
const extension = process.platform === 'win32' ? '.exe' : '';

// 文件路径
const output = `grcov${extension}`;
const filePath = path.join(process.cwd(), 'scripts', output);

// 如果coverage目录不存在，则创建
const dir = path.join(process.cwd(), 'coverage')
if (!fs.existsSync(dir)) {
  fs.mkdirSync(dir)
}

// 如果已经存在覆盖率文件夹，则删除
if (fs.existsSync(path.join(process.cwd(), 'coverage', 'lcov.info'))) {
  fs.unlinkSync(path.join(process.cwd(), 'coverage', 'lcov.info'))
}

if (!process.argv.includes('lcov') && fs.existsSync(path.join(process.cwd(), 'coverage', 'html'))) {
  fs.rmSync(path.join(process.cwd(), 'coverage', 'html'), { recursive: true })
}

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

// 文件路径
let command = filePath
let args = ''
if (process.argv.includes('lcov')) { // 如果参数中有lcov，则生成 lcov.info 文件，否则生成 html 文件
  args = ` . -s . --binary-path ./build/ --llvm-path ${llvmPath} -t lcov --llvm --branch --guess-directory-when-missing --ignore include/* --ignore build/* --ignore test/* -o ./coverage/lcov.info`
} else {
  args = ` . -s . --binary-path ./build/ --llvm-path ${llvmPath} -t html --llvm --branch --guess-directory-when-missing --ignore include/* --ignore build/* --ignore test/* -o ./coverage/`
}

// 删除已存在的多余的default.profraw文件
// const profrawFilePath = path.join(process.cwd(), 'default.profraw')
// if (fs.existsSync(profrawFilePath)) {
//   fs.unlinkSync(profrawFilePath)
// }

// 执行覆盖率测试命令
const execute = spawnSync(command, args.split(' '), {
  cwd: path.join(process.cwd()), // 当前工作目录
  env: process.env,  // 附加当前操作系统的环境变量
  stdio: 'inherit',  // 混合标准输出和错误输出
});

// 如果执行命令返回非零状态，则退出
if (execute.status !== 0) {
  console.log('报错了，请检查上面的错误信息。')
  process.exit(execute.status);
} else {
  console.log('已生成' + (process.argv.includes('lcov') ? 'lcov.info' : 'html') + '覆盖率文件。')
}
