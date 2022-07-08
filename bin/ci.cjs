const fs = require('fs')

const bashStr = `#!/bin/bash
exec llvm-cov gcov "$@"
`

fs.writeFileSync('/usr/bin/llvm-gcov.sh', bashStr, 'utf-8')
