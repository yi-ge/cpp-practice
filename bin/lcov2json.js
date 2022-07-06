#!/usr/bin/env node
const parse = require('lcov-parse')
const path = require('path')

parse(path.join(__dirname, '../coverage.info'), function(err, data) {
    //process the data here
    console.log(data)
});
