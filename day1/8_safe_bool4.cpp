#include <iostream>
#include <optional>
using namespace std;

// pair<bool,int> foo()
// C++17 : optional 클래스 - null 상태와 값을 가질 수 있는 클래스
// www.cppreference.com
//
// gcc : g++ src.cpp -std=c++1z
// vc  : cl src.cpp /std:c++latest
optional<int> foo()
{
	if (1)
		return {};  // 실패...
	return 10;
}

int main() {
	optional<int> oi = foo();
	if (oi)
		cout << *oi << endl;
	return 0;
}
