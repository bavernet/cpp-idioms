int main() {
	const int c = 10;

	auto        a1 = c;     // int

	// ()안에 있는 변수의 선언을 보고 결정
	//decltype(c) d1;         // const int d1;
							// error. 초기값이 필요했다.

	int x[3] = {1, 2, 3};

	auto        a2 = x;     // int *a2 = x;
	auto       &a3 = x;     // int (&a3)[3] = x;
	decltype(x) d2;         // int d2[3];
	decltype(x) d3 = x;     // int d3[3] = x;
							// error. 배열은 값복사를 할 수 없다.
}
