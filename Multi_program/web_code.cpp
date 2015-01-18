// =====================================================================================
//
//       Filename:  web_code.cpp
//
//    Description:  web code test
//
//        Version:  1.0
//        Created:  01/17/2015 01:54:38 PM
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
#include <ctime>
#include <omp.h>
using namespace std;

double calcu(int i)
{
	double x,y;
	double count = 0;
	if(i == 1)
	{
		for(x=0;x<=0.5;x+=0.0001)
			for(y=0;y<=1;y+=0.0001)
			{
				if(x*x+y*y<=1) count++;
			}
	}
	else 
	{
		for(x=0.5001;x<=1;x+=0.0001)
			for(y=0;y<=1;y+=0.0001)
			{
				if(x*x+y*y<=1) count++;
			}
	}

	return count;
}

int main ( int argc, char *argv[] )
{
	time_t startT,endT;
	long count=0;
	long count1=0;
	char space[64];
	long count2=0;

	startT=clock();

#pragma omp parallel sections
	{
#pragma omp section
		{
		//	double x,y;
		//	double count = 0;
		//	for(x=0;x<=0.5;x+=0.0001)
		//		for(y=0;y<=1;y+=0.0001)
		//		{
		//			if(x*x+y*y<=1) count++;
		//		}
			count1 = calcu(1);
		}
#pragma omp section
		{ 
		//	double i,j;
		//	for(i=0.5001;i<=1;i+=0.0001)
		//		for(j=0;j<=1;j+=0.0001)
		//		{
		//			if(i*i+j*j<=1) count2++;
		//		}
			count2 = calcu(2);
		}
	}
	count=count1+count2;
	endT=clock();

	cout << endl << "Calculations took " << endT-startT << "ms.\n";
return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
