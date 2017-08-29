#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
	Base() {}
	void Construct() { foo(); }

	virtual void foo() { cout << "Base foo" << endl; }   // 1

	// 자신을 스스로 만드는 정적함수가 아주 널리 사용됩니다.
	static Base *Create() {
		Base *p = new Base;
		p->Construct();
		return p;
	}
};

class Derived: public Base {
public:
	virtual void foo() { // 2
		cout << "Derived foo" << endl;
	}

	static unique_ptr<Derived> Create() {
		unique_ptr<Derived> p(new Derived);
		p->Construct();
		return move(p);
	}
};

int main(void) {
	unique_ptr<Derived> p = Derived::Create();

	// IOS
	// UIImage *p = UIImage::imageNamed("a.png");

	return 0;
}
