var through = require('through');
tr = through(write, end);

process.stdin.pipe(tr).pipe(process.stdout);
function write(buf)
{
	this.queue(buf.toString().toUpperCase());
}
function end()
{
}
