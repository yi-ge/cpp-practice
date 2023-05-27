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

// 删除build及其子目录下所有的.gcda文件
function deleteAllGcda (filePath) {
  const files = fs.readdirSync(filePath)
  files.forEach((file) => {
    const curPath = path.join(filePath, file)
    if (fs.statSync(curPath).isDirectory()) {
      deleteAllGcda(curPath)
    } else {
      if (path.extname(file) === '.gcda') {
        fs.unlinkSync(curPath)
      }
    }
  })
}

filePath = path.join(process.cwd(), 'build')
if (fs.existsSync(filePath)) {
  deleteAllGcda(filePath)
}


