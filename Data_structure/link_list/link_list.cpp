// =====================================================================================
//
//       Filename:  link_list.cpp
//
//    Description:  implementation of link_list.h
//
//        Version:  1.0
//        Created:  01/23/2015 09:26:25 AM
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
#include <assert.h>
using namespace std;
#include "link_list.h"

C_link_list::C_link_list()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void C_link_list::create_new_node(int val, Node_t **rv )
{
	Node_t *newNode = new Node_t;
	assert(newNode != NULL);
	newNode->val = val;
	newNode->next = NULL;
	*rv = newNode;
}

void C_link_list::push_back(int val)
{
	Node_t *newNode;
	create_new_node(val, &newNode);
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

void C_link_list::push_head(int val)
{
	Node_t *newNode;
	create_new_node(val, &newNode);
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	size++;
}

void C_link_list::pop_back()
{
	assert(head != NULL);
	Node_t *p = head;
	while(p->next != tail && p->next != NULL)
	{
		p = p->next;
	}
	assert(p != NULL);
	tail = p;
	p = p->next;
	tail->next = NULL;
	delete p;
	size--;
}

void C_link_list::pop_head()
{
	assert(head != NULL);
	Node_t *p = head;
	head = p->next;
	delete p;
	size--;
}

void C_link_list::insert(int index, int num, int val)
{
	int ind = 0;
	int count = 0;
	if(index == 0)
	{
		/*push head*/
		while(count < num)
		{
			push_head(val);
			count++;
		}
	}
	else if(index == size-1)
	{
		while(count < num)
		{
			push_back(val);//not the fastest
			count++;
		}
	}
	else
	{
		Node_t *p = head;
		while(ind < index)
		{
			p = p->next;
			ind++;
		}
		assert(p!=NULL);
		while(count < num)
		{
			Node_t *newNode;
			create_new_node(val, &newNode);
			newNode->next = p->next;
			p->next = newNode;
			p = newNode;
			count++;
			size++;
		}
	}
}

void C_link_list::print_list()
{
	if(head == NULL)
	{
		printf("the list is empty. \n");
	}
	else 
	{
		printf("elements in link list: ");
		Node_t *p = head;
		while(p != NULL)	
		{
			printf("%d, ", p->val);
			p = p->next;
		}
		printf("size is: %d\n", size);
	}
}

