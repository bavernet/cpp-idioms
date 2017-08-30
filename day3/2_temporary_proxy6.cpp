// 2_TemporaryProxy - 233 page
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Vector {
	T* buff;
public:
	Vector(): buff(nullptr) { }
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

template <>
class Vector<bool> {
	char* buff;
public:
	Vector(): buff(nullptr) { }
	Vector(int sz) {
		buff = new char[(sz+7)/8];
		memset(buff, 0, (sz+7)/8);
	}
	Vector(const Vector &v) {
		cout << "deep copy implementation" << endl;
	}
	~Vector() {
		delete [] buff;
	}

	class Proxy {
		Vector<bool> &v;
		int idx;
	public:
		Proxy(Vector<bool> &_v, int _idx): v(_v), idx(_idx) {
		}
		operator bool() {
			return v.buff[idx/8] & (1 << (idx & 7));
		}
		Proxy &operator =(bool b) {
			if (b) {
				v.buff[idx/8] |= 1 << (idx & 7);
			} else {
				v.buff[idx/8] &= ~(1 << (idx & 7));
			}
			return *this;
		}
	};

	Proxy operator [](int idx) {
		return Proxy(*this, idx);
	}
};

int main(void) {
	Vector<int> v1(10);
	v1[0] = 10;
	cout << v1[0] << endl;

	Vector<bool> v2(10);

	cout << boolalpha;
	cout << "Before the change: " << endl;
	cout << v2[0] << endl;
	cout << v2[1] << endl;

	v2[0] = true;
	v2[1] = false;

	cout << "After the change: " << endl;
	cout << v2[0] << endl;
	cout << v2[1] << endl;
}
