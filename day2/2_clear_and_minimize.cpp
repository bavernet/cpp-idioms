// 2_clear_and_minimize - 항목 11 - 41 page
// vector의 크기 이야기
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v(10, 3);
	v.resize(7);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(1);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	vector<int> v2 = v; // capacity는 복사하지 않는다

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	vector<int> v3(10, 0);
	v3.resize(7);

	vector<int> (v3).swap(v3);  // clear and minimize
								// Effective STL 책의 내용
								// 필요없는 여분의 메모리를 제거하는 기술

	cout << v3.size() << endl;
	cout << v3.capacity() << endl;

	// c++11 : shink_to_fit()의 등장
	v3.shrink_to_fit();         // 219 page에 기술되어 있음

	//------------------------------
	vector<int> v4(10, 0);
	v4.push_back(1);        // 실험적 경험치로 이순간 50% 더 큰 버퍼로 잡는다
							// 구현마다 틀리다

	cout << v4.size() << endl;      // ?
	cout << v4.capacity() << endl;  // ?
}
