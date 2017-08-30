// 2_TemporaryProxy - 233 page
#include <iostream>
using namespace std;

template <typename T>
class Vector {
	T* buff;
public:
	Vector(int sz) {
		buff = new T[sz];
	}
	Vector(const Vector &v) {
		cout << "deep copy implementation" << endl;
	}
	~Vector() {
		delete [] buff;
	}

	T &operator [](int idx) {
		return buff[idx];
	}
};

int main(void) {
	Vector<int> v1(10);
	v1[0] = 10;
	cout << v1[0] << endl;

	Vector<bool> v2;    // 문제점을 찾아보자
						// 위처럼 만들면 10 바이트 할당


	//Vector<int> v2 = v1;
}
