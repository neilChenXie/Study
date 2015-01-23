// =====================================================================================
//
//       Filename:  link_list.h
//
//    Description:  link_list class
//
//        Version:  1.0
//        Created:  01/23/2015 09:15:29 AM
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

struct Node_t {
	int val;
	Node_t *next;
};

class C_link_list {
private:
	Node_t *head;
	Node_t *tail;
	int size;
	void create_new_node(int val, Node_t **rv);
public:
	C_link_list();
	void push_head(int val);
	void push_back(int val);
	void pop_head();
	void pop_back();
	void insert(int index, int num, int val);
	void print_list();
};
