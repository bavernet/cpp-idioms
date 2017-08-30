// 8_type_deduction
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	auto a1 = n; // n의 타입은? int

	// auto : 메모리 속성이 아닌 값을 저장하는 변수 만들 때
	//        즉, 우변의 const, valatile, reference 속성은 제거되고 타입결정
	const int c = 10;
	auto a2 = c; // const int(x) ==> int(o)
	a2 = 20;

	int &r = n;
	auto a3 = r; // int &(x) ==> int(o)
	a3 = 30;
	cout << n << endl;
}
