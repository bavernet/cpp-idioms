#include <iostream>
using namespace std;

// CRTP 활용 2. CRTP 코드는 결국 모든 파생 클래스가
//              다른 기반 클래스를 사용하게 됩니다.
template <typename T>
class ObjectCount {
	static int cnt;
public:
	ObjectCount() { ++cnt; }
	~ObjectCount() { --cnt; }

	static void print() { cout << cnt << endl; }
};

template <typename T>
int ObjectCount<T>::cnt = 0;

class Truck : public ObjectCount<Truck> { };
class Bike : public ObjectCount<Bike> { };

int main(void) {
	Truck t1, t2;
	Bike b1, b2;

	Truck::print();
}
