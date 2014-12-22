var fs = require('fs');
fs.readdir(process.argv[2],my_filter);

function my_filter(err, list)
{
	if(err)
	{
		return console.log(err);
	}
	//console.log(list);
	new_list = list.filter(fn_filter);
	var i;
	for(i = 0;i < new_list.length;i++)
	{
		console.log(new_list[i]);
	}
}

function fn_filter(list)
{
	var rv = list.search('.'+process.argv[3]);
	//console.log(rv);
	if(rv != -1)
	{
		return true;
	} else {
		return false;
	}
}
