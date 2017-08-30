// 2_TemporaryProxy - 233 page
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

// [] 연산자 만들 때 s[0] 표현이 왼쪽 오른쪽에 올 때를 구별하고 싶다.
// []의 리턴값을 표준 타입이 아닌 객체를 리턴하게 하자..
//
// l-value와 r-value를 구별할 수 있게 된다.

class String {
public:
	char *buff;
	int *ref;
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

	// inner class
	class Proxy {
		String &str;
		int idx;
	public:
		Proxy(String &s, int n): str(s), idx(n) { }
		operator char() {
			cout << "Read 작업 - 복사가 필요없다" << endl;
			return str.buff[idx];
		}
		Proxy &operator =(char c) {
			cout << "쓰기 연산.. 복사본을 만들어야 합니다." << endl;

			int *pr = str.ref;
			char *pb = str.buff;
			str.buff = new char[strlen(str.buff) + 1];
			str.ref = new int(1);
			strcpy(str.buff, pb);
			str.buff[idx] = c;
			if (!--*pr) {
				delete [] pb;
				delete pr;
			}
			return *this;
		}
	};

	Proxy operator [](int idx) {
		cout << "operator[]" << endl;
		return Proxy(*this, idx);
	}
};

int main(void) {
	String s1("hello");
	String s2 = s1;

	char c = s1[0];     // Read 작업.. 자원 분리될 필요가 없다.
	cout << c << endl;

	//s1[0] = 'x';    // Write 작업.. 자원 분리 되어야 한다.
					// COW (Copy On Write): 쓰려고 할 때 복사하자

	// 아래 결과를 생각해보세요.
	cout << s1.buff << endl;
	cout << s2.buff << endl;
}
