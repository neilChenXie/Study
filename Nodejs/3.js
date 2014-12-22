var fn = process.argv[2];
var fs = require('fs');
var file = fs.readFileSync(fn);
var buf = file.toString();
//console.log(buf);
var bufary = buf.split('\n');
console.log(bufary.length-1);
