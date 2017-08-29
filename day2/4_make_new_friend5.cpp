// 4 make new friend - 127 page
#include <iostream>
using namespace std;

template <typename T>
class Complex {
	T re;
	T im;
public:
	Complex(T a = 0, T b = 0): re(a), im(b) { }

	/* 이 경우 T는 class를 위한 타입이기 때문에 template 함수가 아니다
	 * 따라서, 선언만 있는 함수가 되고,
	 * 실제 구현한 friend template 함수와는 상관없는 새로운 함수가 되어
	 * template이 만들어지지 않아 link error가 발생한다
	 */
	//friend ostream &operator <<(ostream &os, const Complex<T> &c);
};

template <typename T>
ostream &operator <<(ostream &os, const Complex<T> &c) {
	return os << c.re << ", " << c.im;
}

int main(void) {
	Complex<int> c1(1, 2);
	Complex<int> c2 = c1;
	Complex<int> c3 = c1;

	cout << c1 << endl;
}
