const fs = require('fs')
const { join } = require('path')
const res = fs.readFileSync(join(__dirname, '../build/testResult.json'), 'utf-8')
console.log(`::set-output name=json::${res}`)