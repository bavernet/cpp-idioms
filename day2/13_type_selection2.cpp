#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// bitset과 같은 클래스를 생각해 봅시다.
template <int N>
struct Bitset {
};

// 조건문 만들기
// 전처리: #if
// 컴파일: ==> 여기서의 if 문이 필요하다. type selction
// 실행:   if ()

int main(void) {
	Bitset<8> b1;
	Bitset<16> b2;
}
