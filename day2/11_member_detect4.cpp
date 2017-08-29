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

// 아래 처럼 하면 foo<int>(0) 이 호출할 함수가 없게 됩니다.
//void foo(...) { cout << "..." << endl; }
template <typename T> void foo(...) { cout << "..." << endl; }

int main() {
	// 아래처럼 사용하게 되면 vector를 명시적으로 만들어서 보낼 필요가 없어진다.
	foo<vector<int>>(0);
	foo<int>(0);
}
