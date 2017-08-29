// 12_부분전문화
#include <iostream>
using namespace std;

// primary template
template <typename T>
struct Stack {
	void push(const T& a) { cout << "T" << endl; }
};

// partial specialization
template <typename T>
struct Stack<T*> {
	void push(const T& a) { cout << "T*" << endl; }
};

// specialization (전문화 혹은 특수화)
template <>
struct Stack<char*> {
	void push(const char *a) { cout << "char*" << endl; }
};


int main(void) {
	Stack<int> s1; s1.push(0);
	Stack<int*> s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
