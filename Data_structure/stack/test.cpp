#include <iostream>
#include <string>
#include "stack.h"
#include "my_type.h"
using namespace std;

int main(int argc, char* argv[])
{
	struct aa l1;
	struct aa l2;
	struct aa l3;
	l1.a1 = 1;
	l1.a2 = 1;
	l2.a1 = 2;
	l2.a2 = 2;
	l3.a1 = 3;
	l3.a2 = 3;
	C_Stack<struct aa> test;
	test.push(l1);
	test.push(l2);
	test.push(l3);

	int i = 0;
	while(i < 3){
		struct aa *rv = test.pop();
		cout<<rv->a1<<endl;
		cout<<rv->a2<<endl;
		i++;
	}
	return 0;
}
