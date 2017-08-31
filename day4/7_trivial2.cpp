// 7_trivial, pod, standard layout, aggregate
// pod(plain old data)
//
// trivial: 아무일도 하지 않는다는 의미를 나타낸다.
#include <iostream>
#include <cstring>
#include <type_traits>
using namespace std;

// 안드로이드 ㅅ스/libutils/include/utils/TypeHelpers.h 에서
// copy_type() 찾아보세요.
class A {
public:
	virtual void foo() {}
};

template <typename T>
void copy_type(T *dst, T *src, int sz) {
	if (is_trivially_copyable<T>::value) {
		cout << "복사생성자가 trivial - memcpy 사용" << endl;
		memcpy(dst, src, sizeof(T) * sz);
	} else {
		cout << "복사생성자가 trivial 하지 않다 - 복사생성자로 복사" << endl;
		while (--sz) {
			new(dst) T(*src);   // 복사생성자 호출 - 오후에 설명
			++dst, ++src;
		}
	}
}

int main() {
	//char s1[10] = "hello";
	//char s2[10];
	A s1[10];
	A s2[10];
	//strcpy(s2, s1);
	copy_type(s2, s1, 10);  // 모든 타입의 배열을 복사하는 함수
}
