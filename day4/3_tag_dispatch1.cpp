#include <iostream>
using namespace std;

int main() {
	//int *p1 = new int[100]; // 실패시 std::bad_alloc 예외발생
	int *p1 = new(nothrow) int[100]; // 실패시 0을 리턴해달라

	if (p1 == 0) {
		cout << "메모리 할당 실패" << endl;
	} else {
		delete [] p1;
	}
}
