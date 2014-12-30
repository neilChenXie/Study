var ws = require('websocket-stream');
var stream = ws('http://localhost:8000');

stream.end('hello\n');
