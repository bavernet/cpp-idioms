// 4 make new friend - 127 page
#include <iostream>
using namespace std;

template <typename T>
class Complex {
	T re;
	T im;
public:
	Complex(T a = 0, T b = 0): re(a), im(b) { }

	/*
	 * option 1
	template <typename U>
	friend ostream &operator <<(ostream &os, const Complex<U> &c);

	Complex<int> 는 다른 모든 Complex<T>와 friends이기 때문에 N:N 관계이다
	*/

	/* option 2 */
	friend ostream &operator <<(ostream &os, const Complex<T> &c) {
		return os << c.re << ", " << c.im;
	}
};

int main(void) {
	Complex<int> c1(1, 2);
	Complex<int> c2 = c1;
	Complex<int> c3 = c1;

	cout << c1 << endl;
}
