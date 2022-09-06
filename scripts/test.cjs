const fs = require('fs')
const { join } = require('path')
const { spawn } = require('child_process')

const test = spawn(join(__dirname, '../build/cpp-practice'));
let result = ''

test.stdout.on('data', (data) => {
  result += data;
  console.log(`${data}`);
  if (data.includes('Global test environment tear-down')) {
    let conclusion = 'neutral'
    if (result.includes('FAILED')) {
      conclusion = 'failure'
    } else if (result.includes('PASSED')) {
      conclusion = 'success'
    }
    const tests = result.match(/(?<=(=\]\s*))(\d+)(?=\stests)/ig)?.[0] || 0
    const failed = result?.split('tear-down')?.pop()?.match(/(?<=(FAILED\s*\]\s*))(\d+)(?=\stest)/ig)?.[0] || 0
    const res = {
      conclusion,
      stats: {
        tests,
        runs: String(Number(tests) - Number(failed)),
        failed
      }
    }
    fs.writeFileSync(join(__dirname, '../build/testResult.json'), JSON.stringify(res), 'utf-8')
    // fs.writeFileSync(join(__dirname, '../build/testResult.json'), JSON.stringify(res, null, 2), 'utf-8')
    console.log(`总计：${tests}个测试，${String(Number(tests) - Number(failed))}个通过，${failed}个失败。`)
    process.exit(0)
  }
});

test.on('close', (code) => {
  console.log(`Test process close all stdio with code ${code}`);
});

test.on('exit', (code) => {
  console.log(`Test process exited with code ${code}`);
});