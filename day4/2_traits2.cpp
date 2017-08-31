#include <iostream>
#include <type_traits>
using namespace std;

// Traits 라이브러리: 특정 타입의 속성을 조사하는 템플릿 라이브러리
//                    메타 함수. 주로 T의 특성을 조사할 때 사용

template <typename T>
void print(T v) {
	if (is_pointer<T>::value)
		cout << "This is a pointer" << endl;
	else
		cout << "This is not a pointer" << endl;
}

int main(void) {
	int n = 10;
	print(n);
	print(&n);
}
