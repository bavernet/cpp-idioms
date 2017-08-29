#include <iostream>
using namespace std;

// 아래 코드가 안드로이드 프레임워크의 최상위 클래스 모양입니다.
class RefBase {
	int mCount = 0;
public:
	void incStrong() { ++mCount; }
	void decStrong() { if (--mCount == 0) delete this; }  // void decStrong(Base *const this)

	// 핵심 1. 부모의 소멸자는 반드시 가상함수이어야 합니다.
	virtual ~RefBase() { cout << "~RefBase" << endl; }
};

class Truck: public RefBase {
public:
	virtual ~Truck() { cout << "~Truck" << endl; }
};

int main(void) {
	Truck *p1 = new Truck;

	p1->incStrong();
	p1->decStrong(); // decStrong(p1); 으로 변해서 호출됩니다.

	return 0;
}
