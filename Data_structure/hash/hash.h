#include <iostream>
#include <string>
using namespace std;

#ifndef HASH_H
#define HASH_H
struct item {
	string name;
	string value;
	item* next;
};

class C_Hash {
	private:
		static const int tableSize = 100;
		item* HashTable[tableSize];
	public:
		C_Hash();
		int hash(string key);
		void add_item(string name, string drink);//1st check empty{1. addnew 2.new link list}
		int num_item_in_index(int index);//count the link list
		void print_table();
};
#endif
