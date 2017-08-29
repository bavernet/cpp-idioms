#include <iostream>
using namespace std;

struct Buffer {
	Buffer(int sz) { cout << "버퍼초기화" << endl; }
};

struct Stream {
	Stream(const Buffer &buf) {
		cout << "버퍼를 사용해서 화면출력" << endl;
	}
};

int main() {
	Buffer buf(4096);
	Stream s(buf);
	return 0;
}
