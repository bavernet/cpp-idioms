// 3 meta - 129 page
//
#include <iostream>
using namespace std;

// 아래 코드를 생각해 보세요
// Meta Programming: 컴파일 할 때 수행되는 함수를 만드는 개념
//                   주로 컴파일 시간 재귀 사용
//                   재귀를 멈추기 위해 템플릿 전문화 사용
template <int N>
struct Factorial {
	// 1번째 시도
	// enum { value = N * Factorial<N-1>::value };

	// 문법의 변화: static const는 클래스안에서 초기화 가능
	// static const int value = N * Factorial<N-1>::value;

	// C++ const 대신 constexpr이 좋다.
	static constexpr int value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<1> {
	enum { value = 1 };
};

int main(void) {
	int n = Factorial<5>::value;
	// 5 * Factorial<4>::value
	//     4 * Factorial<3>::value
	//         3 * Factorial<2>::value
	//             2 * Factorial<1>::value
	//                 1
	cout << n << endl;

	int x = 10;
	int s = Factorial<x>::value; // error. 템플릿 인자로는 변수 안됨
}
