#include <iostream>
using namespace std;

int main(void) {
	int n = 0;
	//double *p1 = (double*)&n;   // C casting is dangerous
	//double *p1 = static_cast<double*>(&n);   // C++ static casting is allowed if it is not dangerous
	double *p1 = reinterpret_cast<double*>(&n); // C++ reinterpret casting is the same with C casting

	const int c = 10;
	//int *p2 = static_cast<int*>(&c); // it is not allowed because removing const attribute is so dangerous
	//int *p2 = reinterpret_cast<int*>(&c); // error
	int *p2 = const_cast<int*>(&c);

	return 0;
}
