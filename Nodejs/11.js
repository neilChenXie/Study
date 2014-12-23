http = require('http');
fs = require('fs');

server = http.createServer(handler);
server.listen(process.argv[2]);
function handler(req,res)
{
	res.writeHead(200,{'content-type':'text/plain'});
	fs.createReadStream(process.argv[3]).pipe(res);
}
