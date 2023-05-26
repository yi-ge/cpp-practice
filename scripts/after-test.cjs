const fs = require('fs')
const path = require('path')

const output = fs.readFileSync(path.join(process.cwd(), 'build/gtest.log'), 'utf-8')
console.log(output)
