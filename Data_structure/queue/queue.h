#include <iostream>
#include <string>
using namespace std;

template<class v1>
class C_Queue {
	private:
		int QueueSize;
		v1* queAry;
		int top;
		int tail;
	public:
		C_Queue(int size) {
			QueueSize = size;
			queAry = new v1[QueueSize];
			top = 0;
			tail = 0;
		};
		~C_Queue(){
			delete queAry;
		};

		void enqueue(v1 data);
		v1 dequeue();
		bool isempty();
		bool isfull();
};

template<class v1>
void C_Queue<v1>::enqueue(v1 data)
{
	if(!isfull()) {
		queAry[tail] = data;
		tail = (tail+1) % QueueSize;
	}
	else {
		cout<<"the queue is full"<<endl;
	}
}

template<class v1>
v1 C_Queue<v1>::dequeue()
{
	v1 rv;
	if(!isempty()) {
		rv = queAry[top];
		top = (top+1) % QueueSize;
		return rv;
	}
	cout<<"the queue is empty"<<endl;
	return -1;
}

template<class v1>
bool C_Queue<v1>::isempty(){
	if(tail == top)
		return true;
	return false;
}

template<class v1>
bool C_Queue<v1>::isfull(){
	int end_tail = tail+1;
	if(end_tail % QueueSize == top)
		return true;
	return false;
}
