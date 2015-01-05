function countWords(data)
{
	//console.log(data);
	return data.reduce(function(res,bb){
		//console.log(aa);
		//console.log(bb);
		res[bb] = ++res[bb] || 1;
		return res;
		//console.log(cc);
		//console.log(dd);
	},{});
}

module.exports = countWords;
