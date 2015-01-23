// =====================================================================================
//
//       Filename:  5_compress.cpp
//
//    Description:  simply compresss a string
//
//        Version:  1.0
//        Created:  01/21/2015 04:25:09 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// ====================================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
using namespace std;

char *compress(const char *input)
{
	char *cp = (char *)input;
	int originLength = strlen(input);
	int newLength;
	int count = 0;
	char *newString = new char[100];
	char *pp = newString;

	memset(newString,0,100);
	strncpy(pp,cp,1);
	while(*cp !='\0'&& *cp !='\n')
	{
		if(*pp != *cp)
		{
			/*record*/
			sprintf(pp+1,"%d",count);
			pp = strchr(pp,'\0');
			/*initial*/
			strncpy(pp,cp,1);
			count = 0;
		}
		count++;
		cp++;
	}
	newLength = strlen(newString);
	cout<<"newLength: "<<newLength<<" oldLength: "<<originLength<<endl;
	if(newLength > originLength)
	{
		return (char *)input;
	}
	else
	{
		return newString;
	}
}

int main ( int argc, char *argv[] )
{
	char input[100];
	assert(NULL != fgets(input, sizeof input, stdin));
	printf("%s\n",compress(input));

	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
