#include <iostream>
#include <list>
using namespace std;

int main(void) {
	// C++14 까지 방식
	list<int> s = {1, 2, 3, 4};
	pair<int,double> p(3, 3.4);


	// C++17 방식
	list s2 = {1, 2, 3, 4};
	pair p2(3, 3.4);
}
