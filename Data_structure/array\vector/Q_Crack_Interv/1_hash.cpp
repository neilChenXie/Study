// =====================================================================================
//
//       Filename:  1_hash.cpp
//
//    Description:  check whether all characters are unique
//
//        Version:  1.0
//        Created:  01/21/2015 03:06:04 PM
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
	bool findFlag = false;
	string sentence;
	cin>>sentence;
	for(int i = 0; i<sentence.length(); i++)
	{
		int index = (int)sentence[i];
		if(rec[index] != true)
		{
			rec[index] = true;
		}
		else
		{
			findFlag = true;
			break;
		}
	}
	if(findFlag == true)
	{
		cout<<"there is duplicate characteristics\n";
	}
	else
	{
		cout<<"there is no duplicate characteristics\n";
	}



	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
