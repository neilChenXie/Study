my_module = require('./func.js');

my_module(process.argv[2],process.argv[3],show_res);

function show_res(err, list)
{
	if(err)
		return console.error("there is a error", err);
	list.forEach(disp);
}

function disp(name)
{
	console.log(name);
}
