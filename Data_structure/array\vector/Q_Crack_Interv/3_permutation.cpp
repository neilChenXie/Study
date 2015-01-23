// =====================================================================================
//
//       Filename:  3_permutation.cpp
//
//    Description:  check wether other sentense is the permutation
//
//        Version:  1.0
//        Created:  01/21/2015 03:36:27 PM
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
	bool rec[256] = { false };
	bool noFlag = false;
	string sen1,sen2;
	cin>>sen1;
	cin>>sen2;
	unsigned int i=0;
	int index;
	while(i<sen1.length())
	{
		index = (int)sen1[i];
		rec[index] = true;
		i++;
	}

	i = 0;
	while(i < sen2.length())
	{
		index = (int)sen2[i];
		if(!rec[index])
		{
			noFlag = true;
			break;
		}
		i++;
	}
	if(noFlag)
	{
		cout<<"string 2 is not the permutation of string 1\n";
	} else
	{
		cout<<"string 2 is the permutation of string 1\n";
	}



	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
