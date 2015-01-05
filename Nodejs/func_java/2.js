function repeat(operate,num)
{
	for(i=0;i < num;i++)
	{
		operate();
	}
}

module.exports = repeat;
