#include <iostream>
using namespace std;

// 단순한 클래스도 template으로 변경하면 어려워집니다.
// T(): zero initialize, T가 표준타입이면, 0
//						 사용자타입이면 디폴트생성자로 초기화
template <typename T>
class Complex {
	T re;
	T im;
public:
	Complex(T a = T(), T b = T()): re(a), im(b) { }

	// template 복사 생성자(일반화된 복사 생성자)
	// "T가 U로 복사될수 있다면
	// "Complex<T>는 Complex<T>로 복사될 수 있어야 한다
	// 복사 생성자를 멤버함수 템플릿으로 만들어야 한다.
	template <typename U>
	Complex(const Complex<U> &c) {
		re = c.re;
		im = c.im;
	}

	template <typename U> friend class Complex;
};

int main(void) {
	Complex<int> c1(1, 2);
	Complex<int> c2 = c1;
	Complex<double> c3 = c1;
}
