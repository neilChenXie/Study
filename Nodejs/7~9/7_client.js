var http = require('http');
var body;
http.get("http://www.google.com/index.html?gws_rd=ssl",handler).on('error',err_handler);

function err_handler(err)
{
	console.log('Get error: '+err.message);
}
function handler(response)
{
	response.setEncoding('utf8');
	body = '';
	response.on("data",data_handler);
	response.on("end",end_handler);
}

function data_handler(data)
{
	console.log('get %d data', data.length);
	body += data;
	//console.log('status: '+data.statusCode);
}

function end_handler()
{
	console.log("Total length of data: %d", body.length);
	console.log('data:');
	console.log(body);
}
