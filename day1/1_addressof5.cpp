#include <iostream>
using namespace std;

struct Base {
	int value = 10; // C++11 은 멤버 초기화 가능
	void print() const { cout << this << endl; }
};
struct Derived: public Base { int value = 20; };
int main(void) {
	Derived d;
	cout << d.value << endl; // 20
	cout << d.Base::value << endl; // 10

	// 파생 클래스를 기반 클래스 타입으로 캐스팅후 사용
	// 기반 클래스와 파생 클래스 간은 static_cast 가능
	cout << static_cast<Base>(d).value << endl;
	cout << static_cast<Base&>(d).value << endl;

	//static_cast<Base>(d).value = 100;   // Error. 임시객체에 값을 넣을 수 없다.
	static_cast<Base&>(d).value = 100;

	static_cast<Base>(d).print();
	static_cast<Base&>(d).print();
	d.print();


	return 0;
}
