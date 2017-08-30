#include <iostream>
using namespace std;;

// friend 함수는 일반 함수이므로 가상함수가 될 수 없다.
// 일반 함수 안에서 가상함수를 호출하는 방법으로 해결한다.
class Animal {
public:
	virtual const char *toString() const { return "Animal"; }
	friend ostream &operator <<(ostream &os, const Animal &a);
};

ostream &operator <<(ostream &os, const Animal &a) {
	return os << a.toString();
}

class Dog : public Animal {
public:
	virtual const char *toString() const { return "Dog"; }
};

int main(void) {
	Animal a;   cout << a << endl;
	Dog b;   cout << b << endl;

	Animal *p = &b;
	cout << (*p) << endl;
}
