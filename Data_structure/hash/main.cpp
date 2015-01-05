#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main(int argc, char* argv[])
{
	C_Hash test;
	cout<<test.hash(argv[1])<<endl;
	return 0;
}
