#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 반복자는 결국 클래스타입의 객체입니다.
// template <typename T>
// class vector_iterator {
//     typedef T value_type;
// };

template <typename T>
typename T::value_type Sum(T first, T last) {
	typename T::value_type s = typename T::value_type();
	for (T it = first; it != last; ++it)
		s += *it;
	return s;
}

int main() {
	list<double> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = Sum(v.begin(), v.end());
	cout << n << endl;
}
