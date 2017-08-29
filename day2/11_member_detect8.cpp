// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

// 멤버 함수 조사하기
// 인자가 한개인 resize 함수가 있는지 조사해 보자.
//
// 핵심원리: resize()함수가 없을 때 치환 실패가 나오는 표현식만 찾으면 된다.
typedef short YES;
typedef char  NO;

// int n;
// decltype(n) n2; // n과 동일타입의 변수 n2
// decltype(foo(0)) n3; // foo(0)의 리턴 타입과 같은 타입

template <typename T> YES foo(decltype(T().resize(0)) *a);
template <typename T> NO  foo(...);

template <typename T>
struct has_resize {
	enum { value = (sizeof(foo<T>(0)) == sizeof(YES)) };
};

int main() {
	if (has_resize<int>::value)
		cout << "resize()가 있습니다." << endl;
	else
		cout << "NONE" << endl;
}
