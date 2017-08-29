// 4 make new friend - 127 page
#include <iostream>
using namespace std;

class Complex {
	int re;
	int im;
public:
	Complex(int a = 0, int b = 0): re(a), im(b) { }

	friend ostream &operator <<(ostream &os, const Complex &c);
};

ostream &operator <<(ostream &os, const Complex &c) {
	return os << c.re << ", " << c.im;
}

int main(void) {
	Complex c1(1, 2);
	Complex c2 = c1;
	Complex c3 = c1;

	cout << c1 << endl;
}
