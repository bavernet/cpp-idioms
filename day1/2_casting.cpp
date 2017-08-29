#include <iostream>
using namespace std;

class Car {
	void incStrong() { ++mCount; }
	void decStrong() { if (--mCount == 0) delete this; }
};

int main(void) {
	Car *p2 = p1;
	p2->incStrong();

	p1->decString();
	p2->decString();
}
