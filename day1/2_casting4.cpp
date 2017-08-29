#include <iostream>
using namespace std;

// 아래 코드가 안드로이드 프레임워크의 최상위 클래스 모양입니다.
// virtual 을 사용하지 않고 template을 이용함으로써 성능향상을 꾀한다.
//
// CRTP (Curiously Recurring Template Pattern)
// 기반 클래스를 만들 때 미래에 만들어질 파생 클래스의 이름을 사용할 수 있게 하는 기법
template <typename T>
class RefBase {
	int mCount = 0;
public:
	void incStrong() { ++mCount; }
	void decStrong() { if (--mCount == 0) delete static_cast<T*>(this); }  // void decStrong(RefBase *const this)

	// 핵심 1. 부모의 소멸자는 반드시 가상함수이어야 합니다.
	~RefBase() { cout << "~RefBase" << endl; }
};

class Truck: public RefBase<Truck> {
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main(void) {
	Truck *p1 = new Truck;

	p1->incStrong();
	p1->decStrong(); // decStrong(p1); 으로 변해서 호출됩니다.

	return 0;
}
