// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

// SFINAE (치환실패는 에러아님)을 사용하는 방식
// 1. 리턴타입으로 치환 실패 만들기
// 2. 함수인자로   치환실패 만들기

typedef short YES;
typedef char  NO;

template <typename T> YES foo(typename T::size_type *a);
template <typename T> NO  foo(...);

template <typename T>
struct has_size_type {
	enum { value = (sizeof(foo<T>(0)) == sizeof(YES)) };
};

int main() {
	if (has_size_type<vector<int>>::value)
		cout << "size_type 이 있습니다." << endl;
	else
		cout << "NONE" << endl;
}
