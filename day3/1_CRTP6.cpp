#include <iostream>
using namespace std;

// CRTP 활용 3.
// 안드로이드소스/libutils/include/utils/Singleton.h
template <typename T>
class Singleton {
private:
	Singleton() { }
	Singleton(const Singleton&) = delete;
	Singleton& operator =(const Singleton&) = delete;

public:
	static T &getInstance(void) {
		static T c;
		return c;
	};

	//friend class T;  // T가 클래스가 아닐 수도 있습니다(e.g. int). error
	friend T; // C++11 부터 템플릿 파라미터도 friend가 될 수 있습니다.
};

//------------------------------------
// Truck 도 싱글톤으로 하고 싶다.
class Truck: public Singleton<Truck> {
private:
	Truck() { }
	Truck(const Truck&) = delete;
	Truck& operator =(const Truck&) = delete;

	friend class Singleton<Truck>;
};

int main(void) {
	Truck &c1 = Truck::getInstance();
}
