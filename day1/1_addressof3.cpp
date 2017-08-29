#include <iostream>
using namespace std;

struct A { int a; };
struct B { int b; };
struct C: public A, public B { int c; };

int main(void) {
	C c;
	A *pA = &c;     // 1000
	//B *pB = &c;   // 1004
	//B *pB = (B*)&c;   // 1004
	//B *pB = static_cast<B*>(&c);   // 1004
				// &c에서 B의 위치를 찾는다...
				// &c에서 B가 없으면 error...
				// 즉, 연관성이 있는 경우만 성공

	B *pB = reinterpret_cast<B*>(&c);   // 1000
				// 무조건 해당 위치를 B처럼 생각하겠다는 것
				// 거의 성공한다 단, const 객체라면 실패
	pB->b = 20;

	cout << c.a << endl;

	cout << &c << endl;
	cout << pA << endl;
	cout << pB << endl;

	return 0;
}
