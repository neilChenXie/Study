concat = require('concat-stream');

var toshow;

process.stdin.pipe(concat(function (chunk)
			{
				toshow = '';
				console.log(chunk.toString().split('').reverse().join(''));
				toshow = chunk.toString().split('').reverse().join('');
			}));

if(toshow) 
{
	console.log(toshow);
}
