// =====================================================================================
//
//       Filename:  7_matrix_check.cpp
//
//    Description:  set 0 when there is a 0 in row or col.
//
//        Version:  1.0
//        Created:  01/22/2015 07:12:10 PM
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

uint8_t row[4];
uint8_t recCol = 0x00;
uint8_t recRow = 0x00;
void check_row(int i)
{
	if(i == 4)
	{
		printf("finished\n");
	}
	else
	{
		/*check each row*/
		int c = 0;
		while(c < 8)
		{
			if(!(0x80>>c & row[i]) && !(recCol & 0x80>>c))
			{
				/*record the row*/
				recCol = recCol | 0x80>>c;
				recRow = recRow | 0x80>>i;
			}
			c++;
		}
		check_row(i+1);
	}
}

int main ( int argc, char *argv[] )
{
	/*8*4 matrix*/
	row[0] = 0xfe;
	row[1] = 0xff;
	row[2] = 0xff;
	row[3] = 0xff;

	check_row(0);
	for(int i = 0; i < 4;i++)
	{
		if(recRow & 0x80>>i)
		{
			row[i] = 0x00;	
		}
		else
		{
			row[i] = row[i] & (~recCol);
		}
	}
	printf("%20x\n",row[0]);
	printf("%20x\n",row[1]);
	printf("%20x\n",row[2]);
	printf("%20x\n",row[3]);
	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
