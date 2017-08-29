#include <iostream>
using namespace std;

// addressof IDioms: 모든 객체의 주소를 구하는 기술
class Point {
public:
	int x, y;
	Point *operator &() const { return 0; }
};

int main(void) {
	Point pt;

	Point *p = addressof(pt);
		// C++11 에서 공식 표준으로 되었습니다.
		// (이전에는 테크닉으로 사용자가 만들어서 사용했었음)

	return 0;
}
