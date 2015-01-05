#include "hash.h"

/*constructor*/
C_Hash::C_Hash()
{
	for(int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->value = "empty";
		HashTable[i]->next = NULL;
	}
}

/*algorithm function*/
int C_Hash::hash(string key)
{
	int sum = 0;
	for(unsigned int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}
	return sum % tableSize;
}

/*func*/
void C_Hash::add_item(string name, string value)
{
	int index = hash(name);
	if(HashTable[index]->name == "empty" && HashTable[index]->value == "empty")
	{
		/*new item*/
		HashTable[index]->name = name;
		HashTable[index]->value = value;
		HashTable[index]->next = NULL;
	}
	else
	{
		/*add to tail*/
		item* Next = HashTable[index];
		item* Ptr = new item;
		Ptr->name = name;
		Ptr->value = value;
		Ptr->next = NULL;
		while(Next->next != NULL)
		{
			Next = Next->next;
		}
		Next->next = Ptr;
	}
}

int C_Hash::num_item_in_index(int index)
{
	int count = 0;
	item* Ptr = HashTable[index];
	if(HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		while(Ptr->next != NULL)
		{
			Ptr = Ptr->next;
			count++;
		}
	}
	return count;
}

void C_Hash::print_table()
{
	int number;
	for(int i = 0; i < tableSize; i++)
	{
	}
}
