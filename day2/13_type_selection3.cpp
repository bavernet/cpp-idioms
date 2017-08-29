#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// 여러 오픈소스에서 나름대로의 이름으로 사용하고 있는 기법
// IF, IfThenElse, Selection(안드로이드)
// C++ 11부터 공식표준으로 conditional을 사용하고 있다
template <bool B, typename T, typename U>
struct IF {
	typedef T type;
};

template <typename T, typename U>
struct IF<false, T, U> {
	typedef U type;
};

//IF<true, int,double>::type t1;  // t1은 int
//IF<false,int,double>::type t2;  // t2는 double

template <int N>
struct Bitset {
	typedef typename IF<(N<=8),char,int>::type TYPE;
	TYPE data;
};

#define show(a) cout << #a << " = " << a << endl

int main(void) {
	Bitset<8> b1;
	Bitset<100> b2;

	show(sizeof(b1));
	show(sizeof(b2));
}
