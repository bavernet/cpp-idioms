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

//-----------------------------
// 버퍼를 가진 스트림 만들기
// 핵심: 멤버의 생성자보다 기반 클래스의 생성자가 먼저 호출된다.
// 즉, 아래 코드는 초기화되지 않은 버퍼를 사용하게 된다.
class MyStream : public Stream {
	Buffer buf;
public:
	MyStream(int sz): buf(sz), Stream(buf) { }
};

int main() {
	MyStream s(4096);
	return 0;
}
