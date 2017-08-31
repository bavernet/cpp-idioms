// 8 template
struct A {
	typedef int DWORD;

	template <typename T>
	struct Data {
		int buf[10];
		typedef int value_type;
	};
};

template <typename T, typename U>
void foo(T a) {
	typename T::DWORD n;    // 1. typename 필요성
	typename T::template Data<U>::value_type d;
}

int main() {
	A a;
	foo<A, double>(a);
}

// 1. C++ 기본 --> 2. C++ Template --> 3. C++ 중급 --> 4. ...
//                    디자인 패턴         STL 과정
