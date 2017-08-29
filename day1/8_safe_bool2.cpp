void true_function() {}

class istream {
public:
	bool fail() { return true; }
#if 0
	// 1번째 선택 - 초기개발
	operator bool() {
		return !fail();
	}
#endif
#if 0
	// 2번째 선택 - C++98/03 버전에서의 실제 구현 방식
	operator void*() {
		return fail()? 0: this;
	}
#endif
#if 0
	// 3번째 선택 - 함수 포인터는 delete 할 수 없다.
	typedef void(*PF)();
	operator PF() {
		return fail()? 0: &true_function;
	}
#endif
	// 4번째 선택 - 멤버 함수 포인터는 side effect를 최소화 할 수 있다.
	struct dummy {
		void true_function() {}
	};

	typedef void(dummy::*SAFE_BOOL)();
	operator SAFE_BOOL() {
		return fail()? 0: &dummy::true_function;
	}
};
istream cin;

int main() {
	int n = 0;
	if (cin) {
	}
	//cin << n;  // bool로 변환되면 이코드가 에러가 발생하지 않는다
	//delete cin;  // void*로 변환되면 컴파일 에러가 발생하지 않는다.

	void (istream::dummy::*f)() = cin; // ?

	return 0;
}
