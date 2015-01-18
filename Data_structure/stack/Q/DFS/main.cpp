/*
 * =====================================================================================
 *
 *       Filename:  8_queen.cpp
 *
 *    Description:  place 8 queens in 8*8 chessboard
 *
 *        Version:  1.0
 *        Created:  01/13/2015 10:35:37 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Chen Xie, 
 *   Organization:  USC
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  line_find(int row)
 *  Description:  
 * =====================================================================================
 */
bool col[8] = { false };
bool rSlope[15] = { false };
bool lSlope[15] = { false };
int total=0;
bool recMatrix[8][8];
void line_find(int row) 
{
	if(row == 8)
	{
		total++;
		cout<<"---------\n";
		for ( int i = 0; i < 8; i++ ) {

			for ( int j = 0; j < 8; j++ )
			{
				if(recMatrix[i][j] == true)
				{
					cout<<"row: "<<i<<" col:"<<j<<endl;
				}
			}
		}
		cout<<"---------\n";
	}
	
	for ( int i = 0; i < 8; i++ ) {

		if (!col[i] && !rSlope[row+i] && !lSlope[row-i+7])
		{
			col[i] = true;
			rSlope[row+i] = true;
			lSlope[row-i+7] = true;
			recMatrix[row][i] = true;
			line_find(row+1);
			col[i] = false;
			rSlope[row+i] = false;
			lSlope[row-i+7] = false;
			recMatrix[row][i] = false;
		}
	}
}		/* -----  end of function line_find(int row)  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	line_find(0);
	cout<<"total: "<<total<<endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
