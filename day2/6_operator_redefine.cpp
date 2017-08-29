class Point {
	int x, y;
public:
	Point(): x(0), y(0) { }
	Point(int a, int b): x(a), y(b) { }
	Point operator +(const Point& p) {
		return Point(x + p.x, y + p.y);
	}
};
