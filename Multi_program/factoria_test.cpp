// =====================================================================================
//
//       Filename:  test.cpp
//
//    Description:  opm.h lib test
//
//        Version:  1.0
//        Created:  01/16/2015 05:08:15 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// =====================================================================================
#include <omp.h>  
#include	<iostream>
#include	<cstdlib>
#include	<string>
#include	<stdio.h>
#include	<string.h>
#include	<stdint.h>
#include <ctime>
using namespace std;
#define MAX_VALUE 15  
  
double get_factoria(int value)
{
	int i = value;
	double temp;
	int tmp_i;
	double res = 0;
	while(i > 0)
	{
		temp = 1;
		tmp_i = i;
		while(tmp_i > 0)
		{
			temp *= tmp_i;
			tmp_i--;
		}
		res += temp;
		i--;
	}
	//cout<<"res: "<<res<<endl;
	return res;
}

double _test(int value)  
{  
	int index;  
	double result;  

	cout<<"#: "<<omp_get_thread_num()<<" nthread: "<<omp_get_num_threads()<<endl;
	result = 0.0;  
	for(index = value + 1; index < MAX_VALUE; index +=2 )  
		result += get_factoria(index);  

	return result;  
}  

//void test()  
//{  
//}

int main ( int argc, char *argv[] )
{
	int index;  
	int time1;  
	int time2;  
	double value1,value2;  
	double result[2];  

	time1 = 0;  
	time2 = 0;  

	value1 = 0.0;  
	time1 = clock();  
	for(index = 1; index < MAX_VALUE; index ++)  
		value1 += get_factoria(index);  

	time1 = clock() - time1;  

	value2 = 0.0;  
	memset(result , 0, sizeof(double) * 2);  
	time2 = clock();  

#pragma omp parallel for num_threads(2)
	for(index = 0; index < 2; index++)  
	{
		result[index] = _test(index);  
	}
	value2 = result[0] + result[1];  
	time2 = clock() - time2;  


	cout<<"value1: "<<value1<<" value2: "<<value2<<endl;
	printf("time1 = %d,time2 = %d\n",time1,time2);  
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
