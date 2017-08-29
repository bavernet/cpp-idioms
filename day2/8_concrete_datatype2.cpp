// 8 concreate datatype - 51 page
#include <iostream>
using namespace std;

// ... 보다는 T 버전이 우선시 된다.
// SFINE
// 함수 템플리 사용시 치환에 실패하면 (아래 코드에서 리턴값 모양)
// 에러가 아니라, 함수후보군에서 제외된다.
//
// "치환 실패는 에러가 아니다"
// "Substitution Failure Is Not An Error" (SFINAE)
template <typename T>
typename T::type foo(T a) { // int::type foo(int)
	cout << "T" << endl;
	return 0;
}

void foo(...) { cout << "..." << endl; }

int main(void) {
	foo(3);
}
