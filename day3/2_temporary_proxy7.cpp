// 2_TemporaryProxy - 233 page
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	//vector<int> v = { 0, 0, 0, 0, 0 };
	vector<bool> v = { 0, 0, 0, 0, 0 };

	// 주의 아래 코드에서 n은 bool 타입이 아닌 Proxy 입니다.
	// temporary proxy를 사용하는 경우 auto 사용시 주의해야 합니다.
	// "Modern Effective C++" 책 "auto" 항목 참조.
	auto n = v[0];  // 우변 수식의 타입으로 좌변의 타입결정

	cout << typeid(n).name() << endl;
}
