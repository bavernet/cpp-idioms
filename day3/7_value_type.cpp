#include <iostream>
#include <vector>
#include <list>
using namespace std;

#if 0
void print(vector<int> &c) {
	int n = c.front();
	cout << n << endl;
}

template <typename T>
void print(vector<T> &c) {
	T n = c.front();
	cout << n << endl;
}
#endif

// 안드로이드소스/libutils/include/utils/Vector.h 열어서 class Vector를 확인
template <typename T>
void print(T &c) {
	typename T::value_type n = c.front();
	// C++11
	// auto n = c.front();
	cout << n << endl;
}

int main() {
	list<double> v = { 1.7, 2, 3 };
	print(v);
}


#if 0
// STL의 원리
template <typename T>
class list {
public:
	typedef T value_type; // 핵심!
};

list<int> s = { 1, 2, 3 };
list<int>::value_type n = s.front(); // 여기서 n의 타입은?  int
#endif
