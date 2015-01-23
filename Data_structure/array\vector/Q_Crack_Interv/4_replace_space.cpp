// =====================================================================================
//
//       Filename:  4_replace_space.cpp
//
//    Description:  replace all space with %20
//
//        Version:  1.0
//        Created:  01/21/2015 03:50:16 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// =====================================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
using namespace std;

int main ( int argc, char *argv[] )
{
	char input[20];
	memset(input, 0, 20);
	fgets(input, 20, stdin);
	/*no extra space*/
	char *p = input;
	unsigned int i = 0;
	int count = 0;
	printf("the length of input: %d\n",(int)strlen(input));
	while(i < strlen(input))
	{
		if(*p == ' ')
		{
			count++;
		}
		p++;
		i++;
	}
	char *cp = input+strlen(input)-1;
	char *ep = input+strlen(input)+2*count;
	*ep = '\0';
	ep--;
	while(ep>=input)
	{
		if(*cp != ' ')
		{
			*ep = *cp;
		}
		else
		{
			*ep = '0';
			ep--;
			*ep = '2';
			ep--;
			*ep = '%';
		}
		ep--;
		cp--;
	}
	printf("the result is: %s\n",input);
	/*with extra space*/
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
