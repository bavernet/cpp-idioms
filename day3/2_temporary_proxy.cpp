// 2_TemporaryProxy - 233 page
#include <iostream>
#include <cstring>
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
};

int main(void) {
	String s1("hello");
	String s2 = s1;
}
