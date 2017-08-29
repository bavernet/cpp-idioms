#include <iostream>
using namespace std;

class Complex {
	int re;
	int im;
public:
	Complex(int a = 0, int b = 0): re(a), im(b) { }
};

int main(void) {
	Complex c1(1, 2);
	Complex c2 = c1;
	Complex c3 = c1;
}
