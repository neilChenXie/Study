var buffer = [];

process.stdin.on('data',data_handler);
process.stdin.on('end', end_handler);

function data_handler(buf)
{
	//console.log(buf);
	buffer.push(buf);
}

function end_handler()
{
	console.log(Buffer.concat(buffer));
}
