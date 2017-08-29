#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A()" << endl; }
	~A() { cout <<"~A()" << endl; }
};

class Test {
	A a;
public:
	Test() { cout << "Test()" << endl; }
	//Test(): a() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main() {
	Test t; // call Test::Test()
	return 0;
}
