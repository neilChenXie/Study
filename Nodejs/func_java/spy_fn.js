function Spy(target, method)
{
	var org_fn = target[method];

	var result = {
		count: 0
	};

	target[method] = function() 
	{
		result.count++;
		return org_fn.apply(this, arguments);
	};
	
	return result;
}

module.exports = Spy;
