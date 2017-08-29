#include <iostream>
using namespace std;

class Test;

// incomplete object (불완전 객체): 전방 선언된 타입으로 선언된 포인터
// --> delete 시에 소멸자가 호출되지 않는다.
//     --> 따라서, 차라리 오류를 내기 위해 delete 전에 sizeof 관련 구문을 삽입
//         이 기법을 [ checked-delete ] 라고 부른다.
void foo(Test *p) {
	sizeof(Test);  // 값을 받지 않아서 일부 컴파일러가 최적화로 지워버리는 경우가 발생
				// 이를 막기 위해서 아래와 같은 방법을 사용한다.
	//enum { type_must_be_complete = sizeof(Test); }    // 1
	//int temp[sizeof(Test)];       // 2
	static_assert(sizeof(Test) > 0, "error, delete incomplete type")    // C++11 부터 지원
	delete p;
}

class Test {
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main(void) {
	Test *p = new Test();
	foo(p);
	return 0;
}
