net = require('net');

server = net.createServer(handler);
server.listen(process.argv[2]);

function handler(sock)
{
	t_date = new Date();
	//console.log(t_date);
	data = t_date.getFullYear().toString()+'-'+(t_date.getMonth()+1)+'-'+t_date.getDate().toString()+' '+t_date.getHours().toString()+':'+t_date.getMinutes().toString()+'\n';
	//console.log(data);
	sock.write(data);
	//sock.end(data);
	sock.end();
}
