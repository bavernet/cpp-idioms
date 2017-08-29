#include <iostream>
using namespace std;

// 핵심: 생성자/소멸자 호출순서
// protected 생성자: 자신은 만들 수 없지만 자식 객체는 만들 수 있게.
class Animal {};
class Dog: public Animal {};

class A {
protected:
	A() { cout << "A()" << endl; }
	~A() { cout <<"~A()" << endl; }
};

class Test: public A {
public:
	Test() { cout << "Test()" << endl; } // 원리. 컴파일러가 생성해준 코드
	//Test(): A() { cout << "Test()" << endl; } // 원리. 컴파일러가 생성해준 코드
	~Test() { cout <<"~Test()" << endl; }
};

int main() {
	//A a; // error
	Test t; // call Test::Test()
	return 0;
}
