/*
 * =====================================================================================
 *
 *       Filename:  1_det_uni_ch.cpp
 *
 *    Description:  detect the string with all different charactor.
 *
 *        Version:  1.0
 *        Created:  01/11/2015 08:22:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Xie
 *   Organization:  USC
 *
 * =====================================================================================
 */

#include <iostream>                          
#include <cstdlib>
#include <string>
#include "func.h"
using namespace std;

int main(){
	//string test = "asdfghjal";
	string test;
	cin>>test;
	string pass;
	C_hash myRec;
	bool findFlag = false;

	cout<<test.length()<<endl;
	for (unsigned int i = 0; i < test.length(); i++ ) {
		pass = test[i];
		cout<<i;
		if ( myRec.find_ext(pass))
		{
			findFlag = true;
		}
		else
		{
			myRec.add_node(pass);
		}
		cout<<i<<endl;
	}
	myRec.print_table();
	if(findFlag)
	{
		cout<<"There is duplicate characteristic\n";
	}
	else{
		cout<<"There is no duplicate characteristic\n";
	}
}
