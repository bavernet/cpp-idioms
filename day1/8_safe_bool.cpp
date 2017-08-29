// 8_safe_bool - 207 page
#include <iostream>
using namespace std;

int main(void) {
	int n = 0;
	/*
	int n1;
	cin >> n;
	cin >> n1;
	cout << "-------" << endl;
	*/

	while (1) {
		cin >> n;   // 사용자가 'a'를 입력했다!!

		if (cin) {  // 어떻게 이 표현이 될까?
					// cin.operator void*()로 변환되고 있다
			cout << "성공" << endl;
			break;
		}

		if (cin.fail()) {
			cout << "입력 실패" << endl;
			cin.clear();    // state 필드를 reset 한다.
			cin.ignore();   // fflush(stdin)
			continue;
		}
		break;
	}

	cout << n << endl; // 얼마가 나올까요?
					// 1) 0     2) -1    3) 10     4) 97
	return 0;
}
