// =====================================================================================
//
//       Filename:  main.cpp
//
//    Description:  test function of graph_link_list.h
//
//        Version:  1.0
//        Created:  01/21/2015 11:38:56 AM
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
#include <ctime>
#include "graph_link_list.h"
using namespace std;

int main ( int argc, char *argv[] )
{
	class C_graph myTest;
	myTest.add_edge(0,1,1);
	myTest.add_edge(1,2,1);
	myTest.add_edge(2,3,1);
	time_t startT = clock();
	myTest.print_graph();
	time_t endT = clock();
	cout<<endT-startT<<endl;
	//myTest.delete_edge(2,1);
	//myTest.print_graph();
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
