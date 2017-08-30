#include <iostream>
using namespace std;

// CRTP 활용 2.
class Car {
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }

	static void print() { cout << cnt << endl; }
};

int Car::cnt = 0;

int main(void) {
	Car c1, c2;

	Car::print();
}
