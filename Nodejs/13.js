http = require('http');
url = require('url');

server = http.createServer(handler);
server.listen(process.argv[2]);

function handler(req,res)
{
	path = url.parse(req.url, true);
	//console.log(path.query.iso);
	time = new Date(path.query.iso);
	if(path.pathname === "/api/parsetime")
	{
		res.writeHeader(200,{'content-type':'text/plain'});
		res.end(JSON.stringify(cre_time(time)));
	}
	if(path.pathname === "/api/unixtime")
	{
		res.writeHeader(200,{'content-type':'text/plain'});
		res.end(JSON.stringify(cre_utime(time)));
	}
}
function cre_time(time)
{
	return {
		hour:time.getHours(),
		minute:time.getMinutes(),
		second:time.getSeconds()
	};
}
function cre_utime(time)
{
	return { unixtime : time.getTime() };
}
