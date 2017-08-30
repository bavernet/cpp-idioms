struct Point {
	int x, y;

	constexpr Point (int a = 0, int b = 0): x(a), y(b) { }

	constexpr int getx() const { return x; }
	constexpr int setx(int a) { x = a; }
	constexpr int gety() const { return y; }
	constexpr int sety(int a) { y = a; }
};

// www.google.com에서 C++ constexpr library
//         ==> https://github.com/bolero-MURAKAMI/Sprout
// constexpr  함수안에서 사용하는 모든 함수는 constexpr
constexpr Point reverse(const Point &p) {
	Point temp;
	temp.setx(p.gety());
	temp.sety(p.getx());
	return temp;
}

int main(void) {
	constexpr Point p(1, 2);
	constexpr Point p2 = reverse(p);

	int a[p2.x];
}
