// =====================================================================================
//
//       Filename:  graph_link_list.cpp
//
//    Description:  Implementation of graph_link_list.h
//
//        Version:  1.0
//        Created:  01/21/2015 10:09:22 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Chen Xie (Neil), xiec@usc.edu
//   Organization:  USC
//
// =====================================================================================
#include "graph_link_list.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
using namespace std;
//--------------------------------------------------------------------------------------
//       Class:  C_graph
//      Method:  C_graph
// Description:  constructor
//--------------------------------------------------------------------------------------
C_graph::C_graph ()
{
	for ( int i = 0; i < MAX_NUM_NODE; i++)
	{
		head[i] = NULL;
	}
	numNode = 0;
}  // -----  end of method C_graph::C_graph  (constructor)  ----- 

void C_graph::create_node(int index, int weight, Node_t **rv)
{
	Node_t *newNode = new Node_t;
	assert(newNode!=NULL);
	newNode->index = index;
	newNode->weight = weight;
	newNode->next = NULL;
	*rv = newNode;
}
/*
 *no duplicate edge, 
 *overwrite when duplicate.
 * */
void C_graph::add_node(int root, int index, int weight)
{
	Node_t *newNode;
	create_node(index, weight, &newNode);
	assert(newNode != NULL);
	/*add to list*/
	if(head[root] == NULL)
	{
		head[root] = newNode;
		numNode++;
	} 
	else 
	{
		Node_t *p = head[root];
		while(p->next != NULL && p->index != index)
		{
			p = p->next;
		}
		if(p->next == NULL)
		{
			p->next = newNode;
		}
		else
		{
			assert(p->index == index);
			p->weight = weight;
			delete newNode;
		}
	}
}

void C_graph::delete_node(int root, int index)
{
	assert(head[root]!=NULL);

	Node_t *p = head[root];
	if(head[root]->index == index)
	{
		head[root] = p->next;
	}
	else
	{
		Node_t *pre;
		do
		{
			pre = p;
			p = p->next;
			assert(p!=NULL);
		}while(p->index != index);
		assert(pre != NULL);
		pre->next = p->next;
	}
	assert(p!=NULL);
	delete p;
	if(head[root]==NULL)
	{
		numNode--;
	}

}

int C_graph::num_node_in_graph()
{
	return numNode;
}

void C_graph::print_graph()
{
	int count = 0;
	int i = 0;
	//while(i < MAX_NUM_NODE)
	while(count < numNode && i < MAX_NUM_NODE)
	{
		if(head[i] != NULL)
		{
			print_one_node(i);
			count++;
		}
		i++;
	}
	assert(count == numNode);
}

void C_graph::print_one_node(int root)
{
	assert(head[root] != NULL);
	printf("node %d:",root);
	Node_t *p = head[root];
	while(p!=NULL)
	{
		printf("%d(w: %d), ",p->index,p->weight);
		p = p->next;
	}
	printf("\n");
}

void C_graph::add_edge(int node1, int node2,int weight)
{
	assert(node1 < MAX_NUM_NODE);
	assert(node2 < MAX_NUM_NODE);
	add_node(node1, node2, weight);
	add_node(node2, node1, weight);
}

void C_graph::delete_edge(int node1, int node2)
{
	assert(node1 < MAX_NUM_NODE);
	assert(node2 < MAX_NUM_NODE);
	delete_node(node1, node2);
	delete_node(node2, node1);
}

