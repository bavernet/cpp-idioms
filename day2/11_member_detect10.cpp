#include <iostream>
using namespace std;

// 144 page 코드를 이해 하려면 아래 코드를 이해해야 합니다.
struct Point {
	int x;
	int y;
};

int main(void) {
	int n = 0;
	int *p1 = &n;

	// 멤버변수를 가르키는 포인터 만들기
	int Point::*p2 = &Point::y; // 멤버 data의 주소 꺼내기
	// 실체가 없기 때문에 실제 메모리를 가르키는 것이 아니라 내부적인 offset을 가르킨다

	cout << p2 << endl; // 버그. cout은 멤버 data 포인터를 제대로 출력안됨. (bool처럼 생각)
	printf("%d\n", p2);

	// 사용하기..
	//*p2 = 10; // 될까요?

	Point p;
	p.*p2 = 10; // .* 연산자 ( Pointer to Member operator 라고 합니다)

	cout << p.y << endl;
}
