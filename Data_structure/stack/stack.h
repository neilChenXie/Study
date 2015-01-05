#include <iostream>
#include <string>
#include "my_type.h"
using namespace std;

template <class TYPE>
class C_Stack
{
	private:
		struct Item{
			TYPE value;
			Item* next;
		};
		Item* stackPtr;
	public:
		void push(TYPE value);
		TYPE* pop();
		//void read_item(Item*p);
		//void Print();

		C_Stack();
		~C_Stack();
};


/*implementation*/
template <class TYPE>
C_Stack<TYPE>::C_Stack() {
	stackPtr = NULL;
}

template <class TYPE>
C_Stack<TYPE>::~C_Stack() {
	Item* p1;
	Item* p2;

	p1 = stackPtr;
	while(p1 != NULL) {
		p2 = p1;
		p1 = p1->next;
		p2->next = NULL;
		delete p2;
	}
}

template <class TYPE>
void C_Stack<TYPE>::push(TYPE value)
{
	Item *newItem = new Item;
	newItem->value = value;
	newItem->next = stackPtr;
	stackPtr = newItem;
}

template <class TYPE>
TYPE* C_Stack<TYPE>::pop()
{
	TYPE *rv;
	if(stackPtr  == NULL){
		cout << "There is nothing in stack\n";
		rv = NULL;
	}
	else
	{
		rv = &stackPtr->value;
		stackPtr = stackPtr->next;
	}
	return rv;
}
