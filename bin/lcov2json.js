#!/usr/bin/env node
const parse = require('lcov-parse')
const path = require('path')
const fs = require('fs')

parse(path.join(__dirname, '../coverage.info'), function(err, data) {
    //process the data here
    // console.log(data)
    const res = {
      conclusion: err ? 'failure' : (data?.[0]?.functions?.hit === data?.[0]?.functions?.found ? 'success' : 'neutral'),
      stats: {
        tests: data?.[0]?.functions?.found,
        runs: data?.[0]?.functions?.hit
      },
      data
    }
    // fs.writeFileSync(path.join(__dirname, '../outputs.json'), JSON.stringify(res, null, 2), 'utf-8')
    console.log(`::set-output name=json::${JSON.stringify(res)}`)
});
