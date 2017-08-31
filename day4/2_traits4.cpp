#include <iostream>
#include <type_traits>
using namespace std;

// Traits 사용법 정리
// 1. is_pointer<T>::value 조사 ---> bool 값 상수입니다.
// 2. is_pointer<T>();  // 객체 생성
//						// T가 포인터이면 부모가 true_type
//						// T가 포인터가 아니면 부모가 false_type

template <typename T>
void print_imp(T v, true_type) {
	cout << v << " : " << *v << endl;
}

template <typename T>
void print_imp(T v, false_type) {
	cout << v << endl;
}

template <typename T>
void print(T v) {
	print_imp(v, is_pointer<T>());
	/*
	// 아래 문장은 if가 false로 결정되어도 *v 코드가 컴파일되므로 error가 발생
	if constexpr (is_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
	*/
}

int main(void) {
	int n = 10;
	print(n);
	print(&n);
}
