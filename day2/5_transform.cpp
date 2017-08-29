class Point {
	int x, y;
public:
	Point(): x(0), y(0) {}
	Point(int a): x(a), y(0) {}
	Point(int a, int b): x(a), y(b) {}
	operator int() { return x; }
};

int main() {
	Point p1;
	Point p2(1, 2);
	int n = p1;     // p1.operator int()
	p2 = n;         // n.operator Point()가 필요
}
