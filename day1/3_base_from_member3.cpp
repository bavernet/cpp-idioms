#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A()" << endl; }
	~A() { cout <<"~A()" << endl; }
};

class B {
public:
	B() { cout << "B()" << endl; }
	~B() { cout <<"~B()" << endl; }
};

class Test: public A {
	B a;
public:
	Test() { cout << "Test()" << endl; }
	//Test(): A(), b() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main() {
	Test t; // call Test::Test()
	return 0;
}
