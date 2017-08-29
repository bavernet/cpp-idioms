// 4_생성자와 가상함수 - 31 page
#include <iostream>
using namespace std;

class Base {
public:
	Base() {  // Base(Base* const this)
		foo(); // this->foo()
			// 이순간 자식의 foo()가 호출된다면
			// 자식의 foo()에서 초기화되지 않은 멤버데이터를 사용하는 위험이 있게 된다.
			// 그래서 생성자에서는 가상함수가 동작하지 않는다.
	}
	virtual void foo() { cout << "Base foo" << endl; }   // 1
};

class Derived: public Base {
	// Data data;
public:
	virtual void foo() { // 2
		// data.func();
		cout << "Derived foo" << endl;
	}
};

int main(void) {
	Derived d; // 1 ? 2 중 어떤 함수가 호출될까요? 잘 생각해보세요
	return 0;
}
