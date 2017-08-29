#include <iostream>
using namespace std;

// 144 page 코드를 이해 하려면 아래 코드를 이해해야 합니다.
struct Point {
	int x;
//	int y;
};

template <typename T, T N> struct check {};

int main(void) {
	check<int,5> c1;        // ok.
	check<char,'a'> c2;       // ok.

	check<int Point::*, &Point::y> c3;



	//check<double,5> c2;     // error. 템플릿 인자로 실수가 될 수 없다.
}
