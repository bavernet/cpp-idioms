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
// 해결책: 버퍼를 가진 기반 클래스 도입 - 26 page 소스
class StreamBuf {
protected:
	Buffer buf;
public:
	StreamBuf(int sz): buf(sz) { }
};

class MyStream : public StreamBuf, public Stream {
public:
	MyStream(int sz): StreamBuf(sz), Stream(buf) { }
};

int main() {
	MyStream s(4096);
	return 0;
}
