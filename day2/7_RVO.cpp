// 7_RVO - 47 page. 항목 13 ==> RVO, NRVO
#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point(int a = 0, int b = 0): x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	Point(const Point &p) { cout << "Point(const Point&)" << endl; }
};

Point foo() {
	// 201x년 이후에 만들어진 컴파일러는 자동으로 RVO를 지원하여 최적화함
	// ==> 이름이 있는 객체도 RVO가 된다. ==> NRVO ( Named RVO ) 라고 불리는 개념
	Point p(1, 2);
	cout << "foo1" << endl;
	return p;   // 이순간 return을 위한 임시객체 생성
				// return Point(p); p를 복사해서 임시객체 생성
				// 리턴용 임시객체의 수명은 함수 호출 구문의 끝에서 파괴
				//
	// 만들고 리턴하지 말고...
	// 만들면서 리턴하자(임시객체로 리턴)
	// Return Value Optimization (RVO) 라는 기술
	//cout << "foo2" << endl;
	//return Point(1, 2);
}

int main() {
	Point p1;
	p1 = foo();
}
