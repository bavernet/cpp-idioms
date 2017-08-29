// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

// Member Detect : 클래스안에 특정 멤버의 존재 여부를 조사하는 기술
//
// 아래 코드는 size_type의 존재 여부에 따라 다른 함수가 호출된다.
template <typename T>
typename T::size_type foo(T *a) {
	cout << "T" << endl;
	return 0;
}

template <typename T> char foo(...) { cout << "..." << endl; }

template <typename T>
struct has_size_type {
	enum { value = (sizeof(foo<T>(0)) != sizeof(char)) };
};

int main() {
	if (has_size_type<vector<int>>::value)
		cout << "size_type 이 있습니다.???" << endl;
	else
		cout << "NONE" << endl;
}
