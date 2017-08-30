// 3 meta - 129 page
//
#include <iostream>
using namespace std;

// constexpr 함수: 함수 인자가 컴파일 시간 상수이며
//                 Meta로 동작한다 (컴파일 시간에 수행)
int Add(int a, int b) {
	return a + b;
}

int main(void) {
	int a = 1, b = 1;
	int x1[Add(1, 2)];  // ok.. 컴파일 시간 수행
	int x2[Add(a, b)];  // error. 실행시간 수행
	int s = Add(a, b);  // ok.. 일반함수처럼 사용가능
}
