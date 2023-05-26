const fs = require('fs')
const path = require('path')

// 删除已存在的default.profraw文件
const filePath = path.join(process.cwd(), 'build', 'default.profraw')
if (fs.existsSync(filePath)) {
  fs.unlinkSync(filePath)
}
