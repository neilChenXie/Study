// =====================================================================================
//
//       Filename:  link_list.cpp
//
//    Description:  Graph represent: link list. Input
//
//        Version:  1.0
//        Created:  01/21/2015 08:53:05 AM
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
#define	NUM_NODE 5			// number of nodes in the graph
struct Node_t {
	int index;
	int weight;
	Node_t *next;
};				// ---  end of struct Node_t  ---

int create_node(int index, int weight, Node_t **rv)
{
	Node_t *newNode = new Node_t;
	if(newNode != NULL)
	{
		newNode->index = index;
		newNode->weight = weight;
		newNode->next = NULL;
		rv = &newNode;
		return 0;
	}
	return 1;
}

int main ( int argc, char *argv[] )
{
	Node_t *head[NUM_NODE];
	/*create new node for node 1*/
	Node_t *newNode;
	if(create_node(2,1,&newNode) != 0)
	{
		fprintf(stderr, "the newNode creation failed\n");
	}
	else
	{
		head[0] = newNode;
	}

	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
