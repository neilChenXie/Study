#include <iostream>
#include "queue.h"
using namespace std;

int main(int argc, char*argv[])
{
	C_Queue<int> test(10);
	test.enqueue(1);
	test.enqueue(3);
	test.enqueue(5);
	test.enqueue(9);
	test.enqueue(7);
	test.enqueue(2);
	test.enqueue(6);
	test.enqueue(4);
	test.enqueue(8);
	for(int i=0;i < 9;i++) {
		cout<<test.dequeue()<<endl;
	}
	return 0;
}
