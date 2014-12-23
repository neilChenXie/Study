var through = require('through');
var split = require('split');
tr = through(write, end);
var count = 0;

process.stdin.pipe(split()).pipe(tr).pipe(process.stdout);
function write(buf)
{
	count++;
	//console.log('\n'+count+'\n');
	if(count % 2 ===0)
		this.queue(buf.toString().toUpperCase()+'\n');
	else 
		this.queue(buf.toString().toLowerCase()+'\n');
}
function end()
{
}
