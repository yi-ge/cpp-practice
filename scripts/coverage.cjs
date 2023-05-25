const { spawnSync } = require('child_process');
const path = require('path');

// 在 Windows 上，二进制文件的扩展名是 .exe
// 在其他系统上，扩展名是空字符串
const extension = process.platform === 'win32' ? '.exe' : '';

// 文件路径
const output = `grcov${extension}`;
const filePath = path.join(process.cwd(), 'scripts', output);

// 执行覆盖率文件生成命令
let command = '' // 如果参数中有lcov，则生成 lcov.info 文件，否则生成 html 文件
if (process.argv.includes('lcov')) {
  command = filePath + ' . -s . --binary-path ./build/ -t lcov --llvm --branch --guess-directory-when-missing --ignore test/\* -o ./coverage/lcov.info'
} else {
  command = filePath + ' . -s . --binary-path ./build/ -t html --llvm --branch --guess-directory-when-missing --ignore test/\* -o ./coverage/'
}
console.log(command)

const execute = spawnSync(command, {
  cwd: path.join(process.cwd()), // 当前工作目录
  env: process.env,  // 附加当前操作系统的环境变量
  stdio: 'inherit',  // 混合标准输出和错误输出
});

// 如果执行命令返回非零状态，则退出
if (execute.status !== 0) {
  console.log('报错了，请检查上面的错误信息。')
  process.exit(execute.status);
} else {
  console.log('如果没有错误信息，表明依赖安装顺利！')
}
