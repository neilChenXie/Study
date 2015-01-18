// =====================================================================================
//
//       Filename:  pthread_test.cpp
//
//    Description:  pthread use
//
//        Version:  1.0
//        Created:  01/17/2015 10:28:16 AM
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
#include <pthread.h>
#include <omp.h>
using namespace std;
#define ENDCON 30

double finalRes1;//serial or parallel
double finalRes2;//serial or parallel
double count11=0;
double count12=0;
double count21=0;
double count22=0;
double x,y,i,j;
int main ( int argc, char *argv[] )
{
	//pthread_t one_id,two_id;
	time_t start1,start2,end1,end2;
	/*serial*/
	start1 = clock();
	for(x=0;x<=0.5;x+=0.0001)
	{
		for(y=0;y<=1;y+=0.0001)
		{
			if(x*x+y*y<=1) count11++;
		}
	}
	for(x=0;x<=0.5;x+=0.0001)
	{
		for(y=0;y<=1;y+=0.0001)
		{
			if(x*x+y*y<=1) count12++;
		}
	}
	finalRes1 = count11+count12;
	end1 = clock();
	cout<<"timer1: "<<end1-start1<<endl;
	cout<<"value1: "<<finalRes1<<endl;
	/*parallel*/
	start2 = clock();
#pragma omp parallel sections 
{
#pragma omp section 
	{
		for(x=0;x<=0.5;x+=0.0001)
		{
			for(y=0;y<=1;y+=0.0001)
			{
				if(x*x+y*y<=1) count21++;
			}
		}
	}
#pragma omp section 
	{
		for(i=0;i<=0.5;i+=0.0001)
		{
			for(j=0;j<=1;j+=0.0001)
			{
				if(i*i+j*j<=1) count22++;
			}
		}
	}
}
	/*end of parallel*/
	//pthread_join(one_id,0);
	//pthread_join(two_id,0);
	finalRes2 = count21+count22;
	end2 = clock();

	cout<<"value2: "<<finalRes2<<endl;
	cout<<"timer2: "<<end2-start2<<endl;
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
