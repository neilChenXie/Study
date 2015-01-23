// =====================================================================================
//
//       Filename:  2_reverse.cpp
//
//    Description:  reverse a sentense
//
//        Version:  1.0
//        Created:  01/21/2015 03:13:29 PM
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

void reverse(char *rp)
{
	char *sp = rp;
	char *ep = rp;
	char temp;
	while(*ep)
	{
		ep++;
	}
	ep--;
	while(ep > sp)
	{
		temp = *sp;
		*sp = *ep;
		*ep = temp;
		ep--;
		sp++;
	}
}

int main ( int argc, char *argv[] )
{
	char sentence[100];
	memset(sentence, 0, sizeof sentence);
	cin>>sentence;
	reverse(sentence);
	printf("the reversed sentence is:%s\n", sentence);
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
