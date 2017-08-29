// 4_생성자와 가상함수 - 31 page
#include <iostream>
using namespace std;

// 객체 생성중 가상함수 호출하기
// 1. 이단생성자 (two phase constructor)
class Base {
public:
	// 생성자에서는 아무일도 하지 말고, 초기화 전용함수 제공
	Base() {}
	void Construct() { foo(); }

	virtual void foo() { cout << "Base foo" << endl; }   // 1
};

class Derived: public Base {
public:
	virtual void foo() { // 2
		cout << "Derived foo" << endl;
	}
};

int main(void) {
	Derived d;
	d.Construct();
	return 0;
}
