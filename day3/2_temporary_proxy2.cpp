// 2_TemporaryProxy - 233 page
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class String {
	char *buff;
	int *ref;
public:
	String(const char *s) {
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);

		ref = new int(1);
	}
	String(const String &s) {
		buff = s.buff;
		ref = s.ref;
		++*ref;
	}
	~String() {
		if (!--*ref) {
			delete [] buff;
			delete ref;
			cout << "deleted" << endl;
		}
	}

	// [] 재정의 : 객체를 배열처럼 사용할 수 있게 한다.
	// 값을 리턴하면 임시객체가 리턴된다. =의 왼쪽에 올 수 없다.
	// s1[0] = 'x'; // error
	// char operator[](int idx)
	//
	// 참조리턴: 임시객체를 만들지 말라. =의 왼쪽에 올 수 있다.
	char &operator [](int idx) {
		return buff[idx];
	}
};

int main(void) {
	String s1("hello");
	String s2 = s1;

	char c = s1[0];     // s1.operator[](0) 가 필요합니다.
	cout << c << endl;

	s1[0] = 'x';
}
