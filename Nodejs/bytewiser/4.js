fs = require('fs');

fs.readFile(process.argv[2], handler);
//fs.readFile(process.argv[2], function(err,buf){
//	if(err)
//{
//	throw err;
//}
////new_b = buf.toString().split('\n');
////console.log(new_b);
//offset = 0;
//for(i = 0;i < buf.length;i++)
//{
//	if (buf[i] === 10) {
//		console.log(buf.slice(offset, i));
//		i++;
//		offset = i;
//	}
//}
//console.log(buf.slice(offset, i));
//});

function handler(err, buf)
{
	if(err)
	{
		throw err;
	}
	//new_b = buf.toString().split('\n');
	//console.log(new_b);
	//console.log(buf);
	offset = 0;
	for(i = 0;i < buf.length;i++)
	{
		if (buf[i] === 10) {
			console.log(buf.slice(offset, i));
			i++;
			offset = i;
		}
	}
	console.log(buf.slice(offset, i));
}
