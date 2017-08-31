// 7_trivial, pod, standard layout, aggregate
// pod(plain old data)
//
// trivial: 아무일도 하지 않는다는 의미를 나타낸다.
#include <iostream>
class A {};

class B { //: public A {
	//A a;
public:
	//B() {}
	B() = default;
	//virtual void foo() {}
};

// 생성자가 trivial 하려면
// 1. 가상함수가 없고,
// 2. 사용자가 만든 생성자가 없고,
// 3. 부모가 없거나 부모ㅢ 생성자가 trivial 하고
// 4. 객체형 멤버가 없거나 객체형 멤버의 생성자가 trivial
// 할 때 생성자는 "trivial" 하다.

int main() {
	// B의 생성자는 trivial 할까요??
	//
	B *p = static_cast<B*>(malloc(sizeof(B)));

	// 이미 존재하는 메모리에 생성자만 호출
	new(p) B;  // placement new라는 개념. p의 생성자 호출

	p->foo();
}
