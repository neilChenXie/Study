process.stdin.on('data',data_handler);

function data_handler(data)
{
	//console.log(data.length);
	var ui8 = new Uint8Array(data);
	//console.log(ui8.length);
	new_js = JSON.stringify(ui8);
	console.log(new_js);
	//console.log(JSON.parse(new_js));
}
