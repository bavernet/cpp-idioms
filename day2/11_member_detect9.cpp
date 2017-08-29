// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
	int foo() { return 0; }
};

template <typename T> T &&xdeclval(); // { return T::(); }

int main(void) {
	// decltype(Test().foo()) n;  // Test안에 디폴드 생성자가 있어야만 한다.
	//
	// C++11 표준 함수 입니다.
	decltype(declval<Test>().foo()) n;

	// n의 타입 구하는 방법 RTTI
	cout << typeid(n).name() << endl;
}
