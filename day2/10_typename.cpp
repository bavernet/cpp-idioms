// 10_typename
class A {
public:
	//...
	// static int DWORD;    // 1
	typedef int DWORD;   // 2
};

int p = 0;

template <typename T>
typename T::DWORD foo(T a) {
	typename T::DWORD *p; // 이 한줄을 해석해 보세요
	// 1. DWORD는 static 멤버 변수인데, 곱하기 p하는 코드
	// 2. DWORD는 typedef 되어 있는 타입이다. 포인터변수 p를 선언하고 있다.
	return 0;
}

int main() {
	A a;
	foo(a);

	A::DWORD *p; // typename을 붙여야할까요? 안붙어야 할까요?
	// typename을 표시하면 error 입니다.
	// 템플릿일 경우만 표기
	// typename T::DWORD
}
