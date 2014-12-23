var fs = require('fs');
var exten;
var cos_f;
function file_filter(path, fext, cos_filter)
{
	exten = fext;
	cos_f = cos_filter;
	fs.readdir(path, deal_res);
}

function deal_res(err, list)
{
	if(err)
	{
		return cos_f(err);
	} 
	else 
	{
		new_list = list.filter(my_filter);
		return cos_f(null, new_list);
	}
}

function my_filter(list)
{
	var rv = list.search('.'+exten);
	if(rv != -1)
		return true;
	return false;
}

module.exports = file_filter;
