const fs = require('fs')
const path = require('path')

// 删除已存在的default.profraw文件
let filePath = path.join(process.cwd(), 'build', 'default.profraw')
if (fs.existsSync(filePath)) {
  fs.unlinkSync(filePath)
}

filePath = path.join(process.cwd(), 'default.profraw')
if (fs.existsSync(filePath)) {
  fs.unlinkSync(filePath)
}
