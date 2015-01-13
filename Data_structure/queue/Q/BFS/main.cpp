/*
 * =====================================================================================
 *
 *       Filename:  flip_coin.cpp
 *
 *    Description:  8 coins in random states, flip 4 successive coins once. find the fastest method. Design the algorithm
 *
 *        Version:  1.0
 *        Created:  01/12/2015 05:13:26 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Chen Xie, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdint.h>
#include <stdio.h>
using namespace std;


struct bit_g {
	uint8_t bit;
	int pre_index;
};				/* ----------  end of struct bit_g  ---------- */

typedef struct bit_g Bit_g_t;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	time_t startTime = clock();
	uint8_t startBit = 0x55;
	bool rec[256] = { false };
	Bit_g_t queue[100];
	int top = 0;
	int pop = 0;
	for ( int i = 0; i < 8; i++)
	{
		queue[pop].bit = startBit;
	}
	queue[pop].pre_index = 0;
	pop++;
	uint8_t flipBit;
	Bit_g_t tmp;
	while ( top < pop ) {
		Bit_g_t dq = queue[top];

		for ( int i = 0; i < 8; i++ ) {
			flipBit = (0xf0>>i | 0xf0<<(8-i));
			uint8_t tmp_p1 = (~(flipBit & dq.bit))&flipBit;
			uint8_t tmp_p2 = ((~flipBit) & dq.bit);
			tmp.bit = tmp_p1 | tmp_p2;
			if(tmp.bit == 0xff || tmp.bit == 0x00)
			{
				//get steps
				int index[10];
				int count = 0;
				index[count] = top;
				while(index[count] != 0)
				{
					index[count+1] = queue[index[count]].pre_index;
					count++;
				}
				//print steps
				while(count >= 0)
				{
					cout<<"----------\n";
					printf("%02x\n",queue[index[count]].bit);
					cout<<"----------\n";
					count--;
				}
				cout<<"----------\n";
				printf("%02x\n",tmp.bit);
				cout<<"----------\n";
				clock_t recTime = clock() - startTime;
				cout<<"run time: "<< recTime<<endl;
				cout<<"pop: "<<pop<<endl;
				return 0;
			}
			//enqueue
			
			if ( !rec[tmp.bit] ) {
				rec[tmp.bit]=true;
				tmp.pre_index = top;
				queue[pop] = tmp;
				pop++;
			}
		}
		top++;
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
