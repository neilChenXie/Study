/*
 * =====================================================================================
 *
 *       Filename:  min_heap.cpp
 *
 *    Description:  use Priority_queue STL build Min heap
 *
 *        Version:  1.0
 *        Created:  01/15/2015 05:33:42 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Chen Xie 
 *   Organization:  USC
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct cmp1 {
	bool operator() (int &a, int &b)
	{
		return a<b;
	}
};				/* ----------  end of struct cmp1  ---------- */

typedef struct cmp1 Cmp1;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	//priority_queue<int> test;
	//priority_queue<int, vector<int>, greater<int> >test;
	priority_queue<int, vector<int>, Cmp1 >test;
	test.push(2);
	test.push(1);
	test.push(5);
	test.push(3);
	test.push(2);

	while(!test.empty())
	{
		cout<<" "<<test.top();
		test.pop();
	}
	cout<<"\n";
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
