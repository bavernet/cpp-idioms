#include <iostream>

// 숙제
char *make_buffer(int sz) {
	char *p = new char[sz];
	return p;
}

struct make_buffer {
	int sz;
	make_buffer(int n): sz(n) { }

	template <typename T>
	operator T*() {
		return new T[sz];
	}
};

int main(void) {
	char *pc = make_buffer(100);
	return 0;
}
