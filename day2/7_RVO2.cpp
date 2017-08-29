// 7_RVO - 47 page. 항목 13 ==> RVO, NRVO
#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point(int a = 0, int b = 0): x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	// Point(const Point &p) { cout << "Point(const Point&)" << endl; }
	// C++11 delete function 문법 : 특정 함수를 제거해 달라
	Point(const Point &p) = delete;
};

int main() {
	// 아래 2줄의 차이점을 생각해 봅시다
	Point p1(1, 2);         // 인자가 2개인 생성자 호출

	// C++17 부터는 복사 생성자가 없어도
	// 아래 코드가 컴파일 됩니다.
	// "mandantory RVO" 라는 문법의 등장.!
	// Point ret = foo(); // 복사생성자가 없어도 임시객체리턴가능
	Point p2 = Point(1, 2); // 1. Point(1, 2)의 임시객체 생성
							// 2. 임시객체를 복사생서자로 p2에 복사
}
