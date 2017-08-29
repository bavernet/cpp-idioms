// 7_return_type_resolver - 203 page
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0): x(a), y(b) { }
	~Point() { cout << "~Point" << endl; }
};

int main(void) {
	//Point pt(1, 2);   // 이름 있는 객체
	//Point(1, 2);  // 클래스 이름(생성자인자): 이름없는 객체, 임시객체
	Point(1, 2), cout << "x" << endl;

	vector<Point> v;
	/*
	Point pt(1, 2);
	v.push_back(pt);
	*/
	v.push_back(Point(1, 2));

	cout << "----" << endl;
}
