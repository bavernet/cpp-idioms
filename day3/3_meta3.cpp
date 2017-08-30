// 3 meta - 129 page
//
// constexpr 함수: 메타함수만들기
// constexpr 변수: 컴파일 시간 상수 만들기
// constexpr class


int main(void) {
	int n = 10;
	const int c1 = n;   // 실행시간 상수
	const int c2 = 10;  // 컴파일 시간 상수. 매크로처럼 문자치환

	// constexpr 상수: 컴파일 상수만 담을 수 있다.
	//constexpr int c3 = n;   // error
	constexpr int c4 = 10;  // ok
}
