#include <iostream>
using namespace std;

class Cursor {
private:
	Cursor() { }
	Cursor(const Cursor&) = delete;
	Cursor& operator =(const Cursor&) = delete;

public:
	static Cursor &getInstance(void) {
		static Cursor c;
		return c;
	};
};

int main(void) {
	Cursor &c1 = Cursor::getInstance();
	Cursor &c2 = Cursor::getInstance();
}
