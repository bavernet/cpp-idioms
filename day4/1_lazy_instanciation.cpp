// 1_지연된인스턴스화
/*
class A
{
public:
	void foo(int a) { *a = 10; }
};
*/
// Lazy Instantiation
// 템플릿으로 부터 진짜 C++ 코드를 만들때, 사용되지 않은 함수는
// C++ 코드로 생성되지 않는다.
template<typename T> class A
{
	T data;
public:
	void foo(T a) { *a = 10; }
};

int main()
{
	A<int> a;
	a.foo(0);
}
