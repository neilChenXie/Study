var map = require('through2-map');
var http = require('http');

var res_msg;

server = http.createServer(handler);
server.listen(process.argv[2]);
function handler(req, res)
{
	//req.pipe(map(function (chunk){
	//	return chunk.toString().toUpperCase();
	//})).pipe(res);
	res_msg = '';
	req.setEncoding('utf8');
	req.on('data',create_res);
	req.on('end',function() {
		res.writeHead(200,{'content-type':'text/plain'});
		res.write(res_msg.toUpperCase());
		res.end();
	});
}

function create_res(msg)
{
	res_msg +=msg;
}
