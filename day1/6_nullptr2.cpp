// nullptr 교재 - 173 page
#include <iostream>
using namespace std;

void foo(void *p) { cout << "void*" << endl; }  // 1
void foo(int n)   { cout << "int" << endl; }    // 2

void goo(char *p) { cout << "char*" << endl; }

struct xnullptr_t {
	// 모든 타입의 포인터로 암시적 형변환 가능
	template <typename T>
	inline operator T*() const { return 0; }

	// 멤버 포인터로의 변환
	template <typename C, typename T>
	inline operator T C::*() const { return 0; }
};
xnullptr_t xnullptr;

int main(void) {
	foo(0);
	foo(xnullptr);
	goo(xnullptr);
	goo(nullptr); // C++11 표준
}
