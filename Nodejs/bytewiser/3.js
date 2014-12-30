process.stdin.on('data',modify);

function modify(buf)
{
	for(i = 0; i < buf.length; i++)
	{
		if(buf[i]===46)
			buf[i] = 0x21;
	}
	console.log(buf);
}
