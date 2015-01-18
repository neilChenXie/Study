// =====================================================================================
//
//       Filename:  vector_test.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  01/16/2015 09:59:14 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// =====================================================================================


#include	<iostream>
#include	<cstdlib>
#include	<string>
#include	<stdio.h>
#include	<string.h>
#include	<stdint.h>
#include <vector>
using namespace std;

int main ( int argc, char *argv[] )
{
	vector<int> vTest;
		for ( int i = 0; i < 18 ; i++ ) vTest.push_back(i);

		for ( vector<int>::iterator i = vTest.begin(); i != vTest.end(); i++ )
		{
			cout<<*i<<endl;
		}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
