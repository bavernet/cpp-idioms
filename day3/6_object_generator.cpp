// 6_object_generator
template <typename T>
void foo(T a) {}

template <typename T, typename U>
struct pair {
	T first;
	U second;
	pair(T a, U b): first(a), second(b) {}
};

template <typename T, typename U>
inline pair<T, U> make_pair(const T &a, const U &b) {
	return pair<T, U>(a, b);
}

int main(void) {
	foo<int>(3);
	foo(3);      // ok.. 컴파일러가 T를 추론(deduction)해준다.
	//pair<int,double> p(3, 3.4);
	auto p = make_pair(3, 3.4);
}
