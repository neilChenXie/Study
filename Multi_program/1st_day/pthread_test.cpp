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

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
using namespace std;
#define ENDCON 30

double finalRes[2];//serial or parallel
double result1;//2 threads
char space[64];
double result2;

void sleep()
{
	useconds_t timeSleep;
	timeSleep = 1000000;
	usleep(timeSleep);
}

void *factoria(void *para)
{
	int index = *((int *)para);
	/*assign CPU*/
	cpu_set_t mask;
	//cpu_set_t get;
	int num = sysconf(_SC_NPROCESSORS_CONF);
	printf("system has %d processor(s)\n", num);
	CPU_ZERO(&mask);
	CPU_SET(index*2+1, &mask);
	if(pthread_setaffinity_np(pthread_self(), sizeof(mask), &mask) < 0)
	{
		fprintf(stderr, "affinity set error\n");
	}
	else
	{
		printf("thread %u is running in processor %d\n", (int)pthread_self(), index*2+1);
	}
	//CPU_ZERO(&get);
	//if (pthread_getaffinity_np(pthread_self(), sizeof(get), &get) < 0) {
	//	fprintf(stderr, "get thread affinity failed\n");
	//}
	//for (j = 0; j < num; j++) {
	//	if (CPU_ISSET(j, &get)) {
	//		printf("processor %d is running\n",j);
	//	}
	//}
	/************/
	double x,y;
	for(x=0;x<=5;x+=0.0001)
	{
		for(y=0;y<=1;y+=0.0001)
		{
			if(x*x+y*y<=1) 
			{
				if(index ==0)
				{
					result1++;
				}
				else
				{
					result2++;
				}

			}
		}
	}
	/**sleep test*****/
	sleep();
	/*****************/
	return 0;
}


int main ( int argc, char *argv[] )
{
	pthread_t one_id,two_id;
	time_t start1,start2,end1,end2;
	/*serial*/
	start1 = clock();
//	for(int i = 1;i < ENDCON; i++)
//	{
//		finalRes[0]+=calcu(i);
//	}
	double x,y;
	for(x=0;x<=5;x+=0.0001)
	{
		for(y=0;y<=1;y+=0.0001)
		{
			if(x*x+y*y<=1) finalRes[0]++;
		}
	}
	sleep();
	for(x=0;x<=5;x+=0.0001)
	{
		for(y=0;y<=1;y+=0.0001)
		{
			if(x*x+y*y<=1) finalRes[0]++;
		}
	}
	sleep();
	end1 = clock();
	/*parallel*/
	int para = 0;
	start2 = clock();
	pthread_create(&one_id,
			0,
			factoria,
			(void *)&para);
	int para2 = 1;
	pthread_create(&two_id,
			0,
			factoria,
			(void *)&para2);
	/*end of parallel*/
	pthread_join(one_id,0);
	pthread_join(two_id,0);
	finalRes[1] = result1+result2;
	end2 = clock();

	cout<<"serial value: "<<finalRes[0]<<endl;
	cout<<"serial timer: "<<end1-start1<<endl;
	cout<<"parallel value: "<<finalRes[1]<<endl;
	cout<<"parallel timer: "<<end2-start2<<endl;
	cout<<(double)(end1-start1)/(end2-start2)<<endl;
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
