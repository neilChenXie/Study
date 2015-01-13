#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main(int argc, char* argv[])
{
	//C_Hash<int, int> test;
	C_Hash<int, string> test;
	test.add_item(1,"chen");
	test.add_item(2,"xie");
	test.add_item(3,"mickey");
	test.add_item(40,"neil");

	string *rv;
	int i = 40;
	rv = test.get_value(40);
	cout<<"num in "<<i<<": "<<test.num_item_in_index(i)<<endl;
	test.delete_item(i);
	cout<<"num in "<<i<<": "<<test.num_item_in_index(i)<<endl;
	cout<<"the res is:"<<*rv<<endl;
	return 0;
}
