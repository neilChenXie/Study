function temp1() {
	console.log(this);
	temp2.call(this);
}
function temp2() {
	console.log(this);
}

var obj = ['adf','qewe'];
temp1.call(obj);
