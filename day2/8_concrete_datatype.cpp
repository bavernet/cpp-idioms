// 8 concreate datatype - 51 page
#include <iostream>
using namespace std;

// 객체를 힙에 만들 수 있게 하는 기술
// 소멸자를 protected에 만들자...
class Test {
public:
	void destroy() { delete this; }

protected:
	~Test() {}
};

int main(void) {
	//Test t;
	Test *p = new Test;
	p->destroy();
}
