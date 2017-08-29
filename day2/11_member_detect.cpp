// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
using namespace std;

// 1단계. 함수와 sizeof
// sizeof(함수호출식): 함수 리턴값의 크기를 구하는 코드
//                     어떤 함수가 호출되는지 조사할 때 사용
//                     함수의 선언부만 있어도 조사 가능!
int foo(int a); // { return 0; }
char foo(double d); // { return 0; }

int main() {
	int n = 10;
	cout << sizeof(n) << endl;          // 4
	//cout << sizeof(foo) << endl;        // error
	cout << sizeof(foo(3.4)) << endl;   // 1
	cout << sizeof(foo(3)) << endl;     // 4
}
