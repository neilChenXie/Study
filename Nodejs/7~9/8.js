http = require('http');
var body;
http.get(process.argv[2], handler).on('err', err_handler);

function handler(response)
{
	body = '';
	response.setEncoding('utf8');
	response.on("data", data_handler);
	response.on('end',end_handler);
}

function data_handler(data)
{
	//console.log(data);
	body += data;
}
function end_handler()
{
	console.log(body.length);
	console.log(body);
}
function err_handler(err)
{
	console.log('Get error: '+err.message);	
}
