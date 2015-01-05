function getShortMessages(data)
{
	//console.log(data);
	new_d =  data.filter(len_fil);
	//console.log(new_d);
	return new_d.map(drill);
}

function len_fil(buf)
{
	return buf.message.length < 50;
}

function drill(buffer)
{
	return buffer.message;
}

module.exports = getShortMessages;
