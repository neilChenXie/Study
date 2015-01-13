#include <iostream>
#include <string>
using namespace std;

#ifndef HASH_H
#define HASH_H
template <class v1, class v2>
class C_Hash {
	private:
		static const int tableSize = 100;
		struct Item{
			v1 key;
			v2 value;
			Item* next;
		};
		Item* HashTable[tableSize];
	public:
		C_Hash();
		int hash(v1 key);
		int num_item_in_index(int index);//count the link list
		void add_item(v1 key, v2 value);//1st check empty{1. addnew 2.new link list}
		void delete_item(v1 key);
		v2* get_value(v1 key);
};

template <class v1, class v2>
C_Hash<v1, v2>::C_Hash()
{
	for(int i = 0; i < tableSize;i++)
	{
		HashTable[i] = NULL;
	}
}

template <class v1, class v2>
int C_Hash<v1, v2>::hash(v1 key)
{
	int index = (int)key % tableSize;
	return index;
}

template <class v1, class v2>
void C_Hash<v1, v2>::add_item(v1 key, v2 value)
{
	int index = hash(key);
	if(HashTable[index]==NULL)
	{
		/*HashTable[index]==NULL*/
		Item* newItem = new Item;
		newItem->key = key;
		newItem->value = value;
		newItem->next = NULL;
		HashTable[index] = newItem;
	}
	else
	{
		/*HashTable[index]!=NULL*/
		Item* p1;
		p1 = HashTable[index];
		while(p1->next != NULL)
		{
			p1 = p1->next;
		}
		Item* newItem = new Item;
		newItem->key = key;
		newItem->value = value;
		newItem->next = NULL;
		p1->next = newItem;
	}
	
}

template <class v1, class v2>
int C_Hash<v1, v2>::num_item_in_index(int index)
{
	int count = 0;
	if(HashTable[index] == NULL)
	{
		return count;
	}
	else
	{
		Item* p1;
		p1 = HashTable[index];
		while(p1 != NULL)
		{
			count++;
			p1 = p1->next;
		}
	}
	return count;
}

template <class v1, class v2>
void C_Hash<v1, v2>::delete_item(v1 key)
{
	int index = hash(key);
	int numItem = num_item_in_index(index);
	if(numItem == 0){
		/*nothing to delete*/
	}
	else if(numItem == 1)
	{
		/*only one*/
		if(HashTable[index]->key == key) {
			Item* p1 = HashTable[index];
			HashTable[index] = NULL;
			delete p1;
		}
	}
	else
	{
		/*multiple*/
		while(HashTable[index]->key == key) {
			Item* p2 = HashTable[index];
			HashTable[index] = p2->next;
			delete p2;
		}
		if(HashTable[index] != NULL){
			Item* p1 = HashTable[index]->next;
			Item* prePtr = HashTable[index];
			while(p1 != NULL)
			{
				if(p1->key == key){
					Item* p2 = p1;
					prePtr->next = p1->next;
					p1 = p1->next;
					delete p2;
				}
				else
				{
					prePtr = p1;
					p1 = p1->next;
				}
			}
		}
	}
}

template<class v1, class v2>
v2* C_Hash<v1, v2>::get_value(v1 key)
{
	int index = hash(key);
	Item* p1 = HashTable[index];
	v2* rv = NULL;
	if(p1 == NULL)
	{
		return rv;
	}
	else 
	{
		while(p1 != NULL) {
			if(p1->key == key) {
				rv = &(p1->value);
				break;
			}
			p1 = p1->next;
		}
	}
	return rv;
}
#endif
