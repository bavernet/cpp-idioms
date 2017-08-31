
template <typename T, typename U>
void foo(T a, U b) {
}

template <typename T>
void foo(T a, T b) {
	*a = b;
}

int main() {
	// if 문은 실행시간 조건문이다.
	// 컴파일 시간에 조건이 false로 결정되어도
#if 0
	if (false)
		foo(1, 3);      // 이 문장은 실행될 수 있다고 판단해서
						// 템플릿으로부터 실제 코드를 생성하게 된다.
	else
		foo(1, 3.4);
#endif
	//-------------------------------------------------------------
	// C++17의 "static if" 또는 "constexpr if"라는 새로운 문법
	// 컴파일 시간에 조사하는 if 문
	if constexpr (false)
		foo(1, 3);      // 이 문장은 실행될 수 있다고 판단해서
						// 템플릿으로부터 실제 코드를 생성하게 된다.
	else
		foo(1, 3.4);

	// C++17 - if init 문법
	if (int a = foo(); a != 0) {
	}
}
