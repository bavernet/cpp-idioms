// 5_policy_base - 183 page (교재는 policy clone)
#include <iostream>
using namespace std;

// 정책 클래스를 사용한 정책의 교체 - policy base design
//                                    "단위전략 디자인"
//                                    "Modern C++ Design"
// C++ 표준 allocator
template <typename T>
class allocator {
public:
	T *allocate(int n) { return new T[n]; }
	void deallocate(T* p) { delete[] p; }
};

template <typename T, typename Ax = allocator<T> >
class vector {
	Ax ax;
public:
	void push_back(const T& a) {
		// 메모리 할당
		// new? malloc? brk?
		T *p = ax.allocate(1);
		*p = a;
	}
};

int main() {
	vector<int> v;
	v.push_back(10);
}
