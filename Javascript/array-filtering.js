//function aa(n)
//{
//	return (n % 2 === 0);
//}

var n = [1,2,3,4,5,6,7,8,9,10];
//var n2 = n.filter(aa(n));
var n2 = n.filter(my_filter);
console.log(n2);

function my_filter(n)
{
	return n % 2 === 0;
}
