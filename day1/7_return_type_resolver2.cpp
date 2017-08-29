// 7_return_type_resolver - 203 page
#include <iostream>
#include <list>
#include <vector>
using namespace std;

#if 0
template <typename T>
void foo(T a) {}

int main(void) {
	foo(1);
	foo(3.4);
	return 0;
}
#endif

#if 0
list<int> *make_container(int sz) {
	list<int> *p = new list<int>;
	for (int i = 0; i < sz; ++i)
		p->push_back(i);
	return p;
}
#endif

// 함수 템플릿의 인자는 암시적 추론 가능하지만 리턴 타입은 될 수 없다
template <typename T>
T *make_container(int sz) {
	T *p = new T;
	for (int i = 0; i < sz; ++i)
		p->push_back(i);
	return p;
}

int main(void) {
	list<int> *p = make_container<list<int> >(10);
	return 0;
}
