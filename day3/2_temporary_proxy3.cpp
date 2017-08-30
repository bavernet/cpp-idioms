// 2_TemporaryProxy - 233 page
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

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
	char &operator [](int idx) {
		return buff[idx];
	}
};

int main(void) {
	String s1("hello");
	String s2 = s1;

	char c = s1[0];     // Read 작업.. 자원 분리될 필요가 없다.
	cout << c << endl;

	s1[0] = 'x';    // Write 작업.. 자원 분리 되어야 한다.
					// COW (Copy On Write): 쓰려고 할 때 복사하자

	// 아래 결과를 생각해보세요.
	cout << s1.buff << endl;
	cout << s2.buff << endl;
}
