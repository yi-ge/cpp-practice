const { spawnSync } = require('child_process');
const path = require('path');
const fs = require('fs');

// 在 Windows 上，二进制文件的扩展名是 .exe
// 在其他系统上，扩展名是空字符串
const extension = process.platform === 'win32' ? '.exe' : '';

// 文件路径
const output = `grcovDownloader${extension}`;
const filePath = path.join(process.cwd(), 'scripts', output);

// 检查 clang++ 是否可用
const checkCommand = spawnSync('clang++', ['-v']);

if (checkCommand.error) {
  console.error('无法找到 clang++。请检查 README.md 文件了解如何安装。');
  process.exit(1);
}

// 如果二进制文件不存在，则编译
if (!fs.existsSync(filePath)) {
  // 指定编译命令
  const command = 'clang++';
  const stdFlag = '-std=c++17';
  const outputFlag = '-o';
  const sourceFile = path.join('.', 'grcovDownloader.cpp');

  // 执行目录为当前目录+ scripts
  const cwd = path.join(process.cwd(), 'scripts');

  // 执行编译命令
  const compile = spawnSync(command, [stdFlag, outputFlag, output, sourceFile], {
    cwd,
    env: process.env,  // 附加当前操作系统的环境变量
    stdio: 'inherit',  // 混合标准输出和错误输出
  });

  // 如果编译命令返回非零状态，则退出
  if (compile.status !== 0) {
    process.exit(compile.status);
  }
}

// 执行编译好的二进制文件
const execute = spawnSync(path.join('.', output), {
  cwd: path.join(process.cwd(), 'scripts'),
  env: process.env,  // 附加当前操作系统的环境变量
  stdio: 'inherit',  // 混合标准输出和错误输出
});

// 如果执行命令返回非零状态，则退出
if (execute.status !== 0) {
  process.exit(execute.status);
}
