#include <iostream>
using namespace std;

// addressof IDioms: 모든 객체의 주소를 구하는 기술
class Point {
public:
	int x, y;
	Point *operator &() const { return 0; }
};

int main(void) {
	Point pt { 1, 1 };
	Point *p1 = &pt;  // 0

	//char *p2 = static_cast<char*>(&pt); // error
	//char *p3 = reinterpret_cast<char*>(&pt); // error
	//char *p4 = &(reinterpret_cast<char>(pt)); // error
				// 서로 다른 타입의 값은 error
				// 캐스팅을 허용한다해도 임시객체
	char *p5 = &(reinterpret_cast<char&>(pt));
	printf("%p\n", p5);

	// 문제점: 객체가 상수라면
	const Point pt2 { 1, 1 };
	//char *p6 = &(reinterpret_cast<char&>(pt2)); // error
	//char *p7 = &(reinterpret_cast<char&>(const_cast<Point&>(pt2))); // error
	Point *p8 = reinterpret_cast<Point*>(&(reinterpret_cast<char&>(const_cast<Point&>(pt2)))); // ok
	printf("%p\n", p8);

	return 0;
}
