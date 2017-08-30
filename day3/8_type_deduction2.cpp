// 8_type_deduction
#include <iostream>
using namespace std;

int main() {
	const int c = 10;
	const int &r = c;

	// auto   : 우변의 const, volatile, reference 무시하고 값의 타입만 가져옴
	// auto & : 우변의 const, volatile 유지,
	//          reference만 무시

	auto a1 = c;    // int
	auto a2 = r;    // int

	auto &a3 = c;   // const int &
	auto &a4 = r;   // const int &
}
