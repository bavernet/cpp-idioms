// 6_object_generator3
#include <list>
#include <iostream>
using namespace std;

template <typename T>
class Vector {
	T *buff;
public:
	Vector() { }
	Vector(int sz, T value) { }

	// 다른 컨테이너를 받는 생성자
	template<typename C> Vector(const C& c) { }

	// 반복자 2개를 인자로 받는 생성자
	template<typename IT> Vector(IT first, IT last) { }
};

// class template deduction guide
Vector()->Vector<int>;
template<typename C> Vector(const C& c)->Vector<typename C::value_type>;
//template<typename IT> Vector(IT first, IT last)->Vector<decltype(*first)>;
template<typename IT> Vector(IT first, IT last)->Vector<typename iterator_traits<IT>::value_type>;

int main(void) {
	Vector v1(10, 3);   // 생성자를 통해서 암묵적인 추론이 가능 (C++17 이후 가능)
	Vector v2;

	list<int> s = { 1, 2, 3 };
	Vector v3(s);
	Vector v4(s.begin(), s.end());
}

// https://nuwen.net/mingw.html
// mingw-15.1.exe 다운로드
