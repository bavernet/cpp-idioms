// 4_생성자와 가상함수 - 31 page
#include <iostream>
using namespace std;

// 생성자에서는 가상함수가 동작하지 않고, 예외가 발생하면
// 소멸자가 호출되지도 않는다
// 해결책중의 하나: 이단 생성자(two phase constructor)


// 객체 생성중 가상함수 호출하기
// 1. 이단생성자 (two phase constructor)
class Base {
	int *p1, *p2;
public:
	/*
	Base() {
		p1 = new int[100];
		p2 = new int[100];
		//...
		throw 1; //생성자에서 실패를 전달하는 대표적인 기술 - 예외
	}
	*/
	// 해결책 1. 생성자에서는 예외가능성이 있는 모든 일을 하지 않는다
	Base(): p1(0), p2(0) { }

	void Construct() {
		p1 = new int[100];
		p2 = new int[100];
		throw 1;
	}

	~Base()
	{
		cout << "~Base" << endl;
		delete[] p1;
		delete[] p2;
	}
};

int main(void) {
	try {
		Base b;
		b.Construct();
	} catch (...) {
	}
	return 0;
}
