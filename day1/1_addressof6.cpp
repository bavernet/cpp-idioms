#include <iostream>
using namespace std;

// addressof IDioms: 모든 객체의 주소를 구하는 기술
class Point {
	int x, y;
public:
	Point *operator &() const { return 0; }
};

int main(void) {
	const Point pt;
	cout << &pt << endl; //왜 주소가 나올까???
	return 0;
}
