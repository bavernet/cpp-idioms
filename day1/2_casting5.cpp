#include <iostream>
using namespace std;

// 아래 코드가 안드로이드 프레임워크의 최상위 클래스 모양입니다.
template <typename T>
class RefBase {
	mutable int mCount = 0; // mutable : 상수에서도 변경가능
public:
	// 참조계수 관리용 함수는 반드시 상수 함수이어야 한다.!!!
	void incStrong() const { ++mCount; }
	void decStrong() const {
		if (--mCount == 0)
			// delete static_cast<T*>(this); // error
			// delete static_cast<T*>(const_cast<RefBase*>(this)); // ok
			delete static_cast<const T*>(this);
	}

	~RefBase() { cout << "~RefBase" << endl; }
};

class Truck: public RefBase<Truck> {
public:
	~Truck() { cout << "~Truck" << endl; }
};

int main(void) {
	const Truck *p1 = new Truck;

	p1->incStrong();
	p1->decStrong();

	return 0;
}
