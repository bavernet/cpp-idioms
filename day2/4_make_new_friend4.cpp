// 4 make new friend - 127 page
#include <iostream>
using namespace std;

void foo(int);

template<typename T>
void foo(T a) {
	cout << "T" << endl;
}

int main(void) {
	foo(3);
	foo(3.4);
}
