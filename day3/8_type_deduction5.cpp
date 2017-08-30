int main() {
	int x[3] = { 1, 2, 3 };
	int *p = x; // ok.. x의 1번째 요소의 주소!!
	int (&r)[3] = x;

	// a1, a2의 타입을 추론하세요
	// x의 타입: int[3]
	auto a1 = x;    // 정확한 타입으로 하면 int a1[3] = x; 이지만 error
					// int* a1 = x; 로 하면 된다.
					// 그래서 a1 = int* 이다.
	auto &a2 = x;   // auto를 int[3] 으로 추론하면
					// int (&a2)[3] = x;
}
