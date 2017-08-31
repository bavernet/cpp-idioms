// 5_policy_base - 183 page (교재는 policy clone)
#include <iostream>
using namespace std;

// C++ 표준 allocator
// T 타입의 메모리 할당기
template <typename T>
class my_allocator {
public:

	// 메모리할당기의 타입을 변경할 때 사용하는 도구
	// policy clone의 핵심
	template <typename U>
	struct rebind {
		typedef my_allocator<U> other;
	};

	T *allocate(int n) { return new T[n]; }
	void deallocate(T* p) { delete[] p; }
};

template <typename T, typename Ax = my_allocator<T> >
class list {
	struct Node {
		T data;
		Node *prev;
		Node *next;
	};

	//Ax ax;
	typename Ax::template rebind<Node>::other ax;
public:
	void push_back(const T& a) {
		Node *p = ax.allocate(1);
		ax.deallocate(p);
	}
};

int main() {
	list<int> v;
	v.push_back(5);
}
