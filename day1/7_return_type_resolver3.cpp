// 7_return_type_resolver - 203 page
#include <iostream>
#include <list>
#include <vector>
using namespace std;

#if 0
// 함수 템플릿의 인자는 암시적 추론 가능하지만 리턴 타입은 될 수 없다
template <typename T>
T *make_container(int sz) {
	T *p = new T;
	for (int i = 0; i < sz; ++i)
		p->push_back(i);
	return p;
}
#endif

#if 1
struct make_container {
	int sz;
	make_container(int n): sz(n) {}

	template <typename T>
	operator T*() {
		T *p = new T;
		for (int i = 0; i < sz; ++i)
			p->push_back(i);
		return p;
	}
};

int main(void) {
	list<int> *p = make_container(10);
	vector<int> *p2 = make_container(10);
	return 0;
}
#endif


#if 0
// 숙제
char *make_buffer(int sz) {
	char *p = new char[sz];
	return p;
}

int main(void) {
	make_buffer(100);
	return 0;
}
#endif
