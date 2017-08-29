// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

// Member Detect : 클래스안에 특정 멤버의 존재 여부를 조사하는 기술
//
// 아래 코드는 size_type의 존재 여부에 따라 다른 함수가 호출된다.
template <typename T>
typename T::size_type foo(T a) {
	cout << "T" << endl;
	return 0;
}

void foo(...) {
	cout << "..." << endl;
}

int main() {
	vector<int> v;
	foo(v);

	int n = 0;
	foo(n);
}
