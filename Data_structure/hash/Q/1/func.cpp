/*
 * =====================================================================================
 *
 *       Filename:  func.cpp
 *
 *    Description:  implementation of func.h
 *
 *        Version:  1.0
 *        Created:  01/11/2015 09:46:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Xie
 *   Organization:  
 *
 * =====================================================================================
 */

#include "func.h"

C_hash::C_hash()
{
	for ( int i = 0; i < table_size; i++)
	{
		rec[i] = NULL;
	}
}

int C_hash::hash(string key)
{
	int res = ((int)key[0]) % table_size;
	return res;
}

void C_hash::add_node(string key)
{
	int index;
	index = hash(key);
	Node_t *newNode = create_new_node(key);
	if(newNode == NULL)
	{
		cout<<"cannot add new node to hash table\n";
	}
	else
	{
		if(rec[index] == NULL)
		{
			rec[index] = newNode;
		}
		else
		{
			Node_t *p;
			p = rec[index];

			while ( p->next != NULL ) {
				p = p->next;
			}
			p->next = newNode;
		}
	}
}

Node_t* C_hash::create_new_node(string key)
{
	Node_t *newNode = new Node_t;
	if(newNode == NULL)
	{
		cout<<"cannot get more buffer\n";
		return NULL;
	}
	else
	{
		newNode->key = key;
		newNode->count = 1;
		newNode->next = NULL;
		return newNode;
	}
}

bool C_hash::find_ext(string key)
{
	int index = hash(key);
	if(rec[index] == NULL)
	{
		return false;
	}
	else
	{
		Node_t *p = rec[index];
		
		while ( p!=NULL ) {
			if ( p->key == key ) {
				p->count++;
				return true;
			}
		}
		return false;
	}
}

void C_hash::print_table()
{
	
	for ( int i = 0; i < table_size; i++ ) {
		if ( rec[i] != NULL ) {
			Node_t *p = rec[i];

			while ( p != NULL ) {
				cout<<"---------------\n";
				cout<<p->key<<": "<<p->count<<endl;
				cout<<"---------------\n";
				p = p->next;
			}
		}
	}
}
