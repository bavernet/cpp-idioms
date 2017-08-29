// 1_checked_delete2
#include <iostream>
#include <memory>
using namespace std;

// unique_ptr의 자원 삭제를 위한 함수 객체
struct Freer {
	void operator()(void* p) {
		cout << "free" << endl;
		free(p);
	}
};

int main(void) {
	//unique_ptr<int> p1(new int);
	// --> default_delete<int>: delete 수행하는 함수
	//     --> 이 부분에서 checked_delete 를 수행한다
	unique_ptr<int,default_delete<int> > p1(new int);
	unique_ptr<int,Freer> p2((int*)malloc(sizeof(int)));
	return 0;
}
