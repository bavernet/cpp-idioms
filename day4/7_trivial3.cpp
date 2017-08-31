// 7_trivial, pod, standard layout, aggregate
// pod(plain old data)
//
// trivial: 아무일도 하지 않는다는 의미를 나타낸다.
#include <iostream>
#include <thread>
using namespace std;

int x = 0;

void foo() {}

int main() {
	thread t1(&foo), t2(&foo), t3(&foo);

	t1.join();
	t2.join();
	t3.join();
	printf("%d\n", x);
}
