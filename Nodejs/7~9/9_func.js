http = require('http');
var body = [];
var rec;
count = 0;
function http_get(i)
{
	http.get(process.argv[i+2],handler).on('error',err_handler);
}

function handler(response)
{
	rec = i;
	console.log(rec);
	body[rec] = '';
	response.setEncoding('utf8');
	response.on("data", data_handler);
	response.on('end', function(){
		count++;
		if(count === 3)
	{
		show();
	}
	});

}

function data_handler(data)
{
	body[rec] += data;
}

function show()
{
	for(n = 0; n < 3; n++)
	{
		console.log(body[n]);
	}
}
function err_handler(err)
{
	console.log('Get error: '+err.message);	
}
function end_handler()
{
	//console.log(body.length);
}
exports.get = http_get;
