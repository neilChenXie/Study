http = require('http');

http.get(process.argv[2], handler).on('err', err_handler);

function handler(response)
{
	response.setEncoding('utf8');
	response.on("data", data_handler);
}

function data_handler(data)
{
	console.log(data);
}

function err_handler(err)
{
	console.log('Get error: '+err.message);	
}
