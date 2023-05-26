// const { execSync } = require("child_process")
const fs = require('fs')
const path = require('path')

// 删除已存在的default.profraw文件
const filePath = path.join(process.cwd(), 'build', 'default.profraw')
if (fs.existsSync(filePath)) {
  fs.unlinkSync(filePath)
}

// 删除已存在的.gcda文件
// // find ${CMAKE_BINARY_DIR} -name \*.gcda -delete
// const CMAKE_BINARY_DIR = path.join(process.cwd(), 'build')
// const out = execSync("find", [CMAKE_BINARY_DIR, "-name", "*.gcda", "-delete"], {
//   cwd: path.join(process.cwd()), // 当前工作目录
//   env: process.env,  // 附加当前操作系统的环境变量
//   stdio: 'inherit',  // 混合标准输出和错误输出
// })
// console.log(out.toString())

// 删除与当前单元测试无关的.gcda文件
// # find build -name "*.gcda" -not -path "*flip_columns_for_maximum_number_of_equal_rows*" -exec rm {} \;
