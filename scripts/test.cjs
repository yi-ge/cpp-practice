const { spawn } = require("child_process");
const fs = require("fs");

// 使用spawn函数创建一个子进程，使其继承stdio以保留颜色信息
const cp = spawn("d:\\Project\\cpp-practice\\build\\cpp-practice.exe", ["--gtest_color=yes"], {
  stdio: ["inherit", "pipe", "pipe"],
  env: process.env,
});

// 创建一个可写流，将子进程的输出写入test.log文件
const logStream = fs.createWriteStream("test.log");

// 监听stdout数据，写入文件并显示在控制台上
cp.stdout.on("data", (data) => {
  process.stdout.write(data); // 在控制台上显示
  logStream.write(data); // 写入文件
});

// 监听stderr数据，处理错误信息
cp.stderr.on("data", (data) => {
  console.error(`stderr: ${data}`);
});

// 子进程退出时的处理
cp.on("close", (code) => {
  logStream.end(); // 关闭文件流

  if (code !== 0) {
    console.error(`子进程退出，退出码：${code}`);
  }
});
