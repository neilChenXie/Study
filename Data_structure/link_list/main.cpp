// =====================================================================================
//
//       Filename:  main.cpp
//
//    Description:  test link list class
//
//        Version:  1.0
//        Created:  01/23/2015 09:14:08 AM
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
#include "link_list.h"
int main ( int argc, char *argv[] )
{
	class C_link_list test;
	int i = 2;
	while(i<8) {
		test.push_back(i);
		i++;
	}
	test.print_list();
	test.push_head(12);
	test.print_list();
	test.push_back(1);
	test.print_list();
	test.pop_head();
	test.print_list();
	test.pop_back();
	test.print_list();
	test.insert(2,2,31);
	test.print_list();
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
