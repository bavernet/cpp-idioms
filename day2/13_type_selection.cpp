#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(void) {
	bitset<8> b;    // 단점. 크기로 변수 사용안됩니다.
					// 해결책. boost::dynamic_bitset<> b(16)
	b.reset();
	b[4].flip();
	b.set(3);

	unsigned long n = b.to_ulong();
	string s = b.to_string();
	cout << s << endl;
	cout << n << endl;
}
