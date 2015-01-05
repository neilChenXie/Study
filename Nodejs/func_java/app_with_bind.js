//window.color = 'red';

var o = {color: 'blue'};

function showColor(){
	console.log(this.color);
}

//showColor();
var tryit = showColor.bind(o);
tryit();
o.color = 'black';
tryit();
