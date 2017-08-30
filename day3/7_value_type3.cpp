#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 반복자의 종류
// 1. 객체형 반복자(v.begin() 등으로 꺼내는 것)
// 2. 진짜 포인터..
// 위 2가지의 차이점을 없애는 도구
#if 0
template<typename T>
struct my_iterator_traits {
	typedef typename T::value_type value_type;
};

template<typename T>
struct my_iterator_traits<T*> {
	typedef T value_type;
};
#endif

template <typename T>
typename iterator_traits<T>::value_type Sum(T first, T last) {
	typename iterator_traits<T>::value_type s = typename iterator_traits<T>::value_type();
	for (T it = first; it != last; ++it)
		s += *it;
	return s;
}

int main() {
	list<double> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = Sum(v.begin(), v.end());
	cout << n << endl;

	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n2 = Sum(x, x + 10);
	cout << n2 << endl;
}
