/*
 * =====================================================================================
 *
 *       Filename:  3_cups.cpp
 *
 *    Description:  cups: A, B, C ml. Begin with A full, end with x ml in C.
 *
 *        Version:  1.0
 *        Created:  01/12/2015 01:08:15 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Chen Xie 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct cup_g {
	int now_has[3];
	int pre_index;
};				/* ----------  end of struct cup_g  ---------- */

typedef struct cup_g Cup_g_t;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
/*
 * const var
 */
	const int cups[3] = {5, 4, 3};
	const int finalRequest = 2;
/* 
 * for data_structure: Queue;
 */
	Cup_g_t queue[100];
	int top = 0;
	int pop = 0;
	bool recFlag[5][4][3] = { false };
/*
 * tmp;
 */
	Cup_g_t tmp;
	clock_t begTime = clock();
	clock_t recTime;
/*
 * initial
 */
	tmp.now_has[0] = cups[0];
	tmp.now_has[1] = 0;
	tmp.now_has[2] = 0;
	tmp.pre_index = 0;
	/**enqueue:Data structure**/
	queue[pop] = tmp;
	pop++;
	/**************************/
/*
 *while
 */
	while ( top < pop ) {
		Cup_g_t dq = queue[top];
		for ( int i = 0; i < 3; i++ ) {
			if ( dq.now_has[i] != 0 ) {
				for ( int j = 0; j < 3; j++ ) {
					if(j != i)
					{
						tmp = dq;
						int jLeft = cups[j] - tmp.now_has[j];
						if(jLeft < dq.now_has[i])
						{
							tmp.now_has[j] = cups[j];
							tmp.now_has[i] = dq.now_has[i] - jLeft;
						}
						else
						{
							tmp.now_has[j] = tmp.now_has[j]+tmp.now_has[i];
							tmp.now_has[i] = 0;
						}
						tmp.pre_index = top;

						if (recFlag[tmp.now_has[0]][tmp.now_has[1]][tmp.now_has[2]]) {
							continue;
						}
						if(tmp.now_has[2] == finalRequest){
							//print steps;
							int index[10];
							int count = 0;
							index[0] = tmp.pre_index;
							while(index[count] != 0)
							{
								index[count+1] = queue[index[count]].pre_index;
								count++;
							}
							while(count >= 0)
							{
								cout<<"----------------\n";
								cout<<"cup A: "<<queue[index[count]].now_has[0]<<endl;
								cout<<"cup B: "<<queue[index[count]].now_has[1]<<endl;
								cout<<"cup C: "<<queue[index[count]].now_has[2]<<endl;
								cout<<"----------------\n";
								count--;
							}
							cout<<"----------------\n";
							cout<<"cup A: "<<tmp.now_has[0]<<endl;
							cout<<"cup B: "<<tmp.now_has[1]<<endl;
							cout<<"cup C: "<<tmp.now_has[2]<<endl;
							cout<<"----------------\n";
							recTime = clock() - begTime;
							cout<<"run time: "<<((float)recTime)/CLOCKS_PER_SEC<<endl;
							cout<<"pop: "<<pop<<endl;
							return 0;
						}
						/****enqueue: Data structure*****/
						recFlag[tmp.now_has[0]][tmp.now_has[1]][tmp.now_has[2]] = true;
						queue[pop] = tmp;
						pop++;
						/********************************/
					}
				}
			}
		}
		top++;
	}
	
/*
 * end of program
 */
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
