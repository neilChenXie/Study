var fs = require('fs');

fs.readFile(process.argv[2], 'utf8', deal_file);

function deal_file(err, buf)
{
	if(err)
	{
		return console.error(err);
	}
	//console.log(buf);
	buf_array = buf.toString().split('\n');
	console.log(buf_array.length-1);
}
