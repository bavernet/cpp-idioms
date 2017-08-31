#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void print(T v) {
	if (T가 포인터라면)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main(void) {
	int n = 10;
	print(n);
	print(&n);
}
