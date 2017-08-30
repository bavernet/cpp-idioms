// 8_type_deduction
#include <iostream>
using namespace std;

int main() {
	int n = 10;
	int *p = &n;

	double d = 3.4;
	double *p2 = &d;    // 주소 구하는 방법: &변수이름

	int x[3] = { 1, 2, 3 };   // 변수 이름: x, 타입: int[3]
	int (*p3)[3] = &x;


	//----------------------------------------------
	// 핵심 2.
	int n1 = 10;
	int n2 = n1;

	double d1 = 3.4;
	double d2 = d1;

	int x1[3] = { 1, 2, 3 };
	//int x2[3] = x1;   // error. 배열은 복제 될 수 없다.

	int *p2 = x1;
}
