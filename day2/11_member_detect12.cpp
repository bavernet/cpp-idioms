// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
};

typedef short YES;
typedef char  NO;

template <typename T, T N> struct check;

template <typename T> YES foo(check<int T::*, &T::y> *a);
template <typename T> NO  foo(...);

template <typename T>
struct has_y {
	enum { value = (sizeof(foo<T>(0)) == sizeof(YES)) };
};

int main() {
	if (has_y<Point>::value)
		cout << "T::y가 있습니다." << endl;
	else
		cout << "NONE" << endl;
}
