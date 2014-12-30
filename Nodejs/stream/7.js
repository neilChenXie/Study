http = require('http');
through = require('through');

tr = through(write);
server = http.createServer(handler);
server.listen(process.argv[2]);

function handler(req,res)
{
	if(req.method === 'POST')
	{
		//res.writeHead(200,{'content-type':'text/plain'});
		req.pipe(through(write)).pipe(res);
		//req.pipe(tr);
		//res.end();
		//req.pipe(through(function(buf){
		//	this.queue(buf.toString().toUpperCase());
		//})).pipe(res);
	}
}

function write(buf)
{
	new_b = buf.toString().toUpperCase();
	console.log(new_b);
	this.queue(new_b);
	//this.queue(buf.toString().toUpperCase());
}

function end()
{
	
}
