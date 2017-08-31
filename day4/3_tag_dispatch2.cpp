#include <iostream>
using namespace std;

void *operator new(size_t sz) {
	cout << "new1" << endl;
	void *p = malloc(sz);
	if (!p) throw std::bad_alloc();
	return p;
}

#if 0
// Tag Dispatch
// : empty class를 만들어서 function overloading에 사용하는 기법
struct nothrow_t {};    // empty class : 어떠한 멤버도 없는 클래스(구조체)
nothrow_t nothrow;      // sizeof(nothrow) ==> 1
#endif

void *operator new(size_t sz, const nothrow_t &a) noexcept {
	cout << "new1 w/ nothrow" << endl;
	return malloc(sz);
}

int main() {
	int *p1 = new int;          // operator new(sizeof(int))
	int *p2 = new(nothrow) int; // operator new(sizeof(int), nothrow)
}
