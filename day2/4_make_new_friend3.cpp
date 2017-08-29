// 4 make new friend - 127 page
#include <iostream>
using namespace std;

void foo(int a) {
	cout << "int" << endl;
}

void foo(double a);

int main(void) {
	foo(3);
	foo(3.4);
}
