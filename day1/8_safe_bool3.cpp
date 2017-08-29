class istream {
public:
	bool fail() { return true; }

	// C++ explicit 변환 연산자 : 암시적 변환은 안되고 명시적 변환만 가능
	// 단, if문 안에서는 암시적 변환 가능
	explicit operator bool() { return !fail(); }
};
istream cin;

int main() {
	bool b1 = cin; // error
	bool b2 = static_cast<bool>(cin); // ok

	int n = 10;
	cin << n; // error

	if (cin) {}

	return 0;
}
