// 12_부분전문화
#include <iostream>
using namespace std;

template<typename T, typename U>
struct Test {
	void foo() { cout << "T,U" << endl; }
};

template<typename T, typename U>
struct Test<T,U*> {
	void foo() { cout << "T,U*" << endl; }
};

template<typename T, typename U>
struct Test<T*,U*> {
	void foo() { cout << "T*,U*" << endl; }
};

// 아래 코드가 핵심입니다.
// primary template은 템플릿 인자가 2개 이지만
// 부분 특수화 버전은 다를 수도 있다는 점이 핵심..
template<typename T>
struct Test<T,short> {
	void foo() { cout << "T,short" << endl; }
};

template<typename T>
struct Test<T,T> {
	void foo() { cout << "T,T" << endl; }
};

template<>
struct Test<short,char> {
	void foo() { cout << "short,char" << endl; }
};

int main(void) {
	Test<int,double>     t1; t1.foo(); // T, U
	Test<int,double*>    t2; t2.foo(); // T, U*
	Test<int*,double*>   t3; t3.foo(); // T*, U*
	Test<int,short>      t4; t4.foo(); // T, short
	Test<int,int>        t5; t5.foo(); // T, T
	Test<short,char>     t6; t6.foo(); // short, char
	// 결과가 위처럼 나오게 해보세요.
}
