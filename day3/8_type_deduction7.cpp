int x = 0;

int  foo() { return x; }
int &goo() { return x; }

int main() {
	x     = 10; // ok.. x는 메모리에 존재한다.
	//foo() = 10; // error. 값을 리턴하는 함수는 임시객체로 리턴된다.
	            // 임시객체는 lvalue가 될 수 없다.
	goo() = 10; // ok.. 참조를 리턴하는 함수는 lvalue가 될 수 있다.
	            // 즉, lvalue가 되려면 참조가 리턴되야 한다.
	//-------------------------------------------------------------

	int  n = 10;
	int *p = &n;

	decltype(p)  d1;  // int *

	// 핵심 : 변수에 연산자를 포함하는 식이 있을 때..
	// *p = 20;
	//decltype(*p) d2;  // int &
	                  // error. d2는 참조인데, 초기값이 없다.

	auto a1 = *p;     // int, 우변의 참조속성을 제거하고 판단하므로

	int x[3] = { 1, 2, 3 };

	//decltype(x[0]) d3; // int &
	auto a2 = x[0];    // int

	int n3 = 0;
	decltype(n3 + n3) d4; // int    --> (n3 + n3) = 10 형태가 될수 없다.
	//decltype(++n) d5;     // int &
	decltype(n++) d6;     // int
}
