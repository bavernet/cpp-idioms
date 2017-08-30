#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

int main() {
	list<int> s = { 1, 2, 3 };

	auto p = s.begin();  // 또는 list<int>::iterator p = s.begin();

	decltype(p)   d1;   // list<int>::iterator    (반복자 타입)
	//decltype(*p)  d2;   // int &  (반복자가 가리키는 타입&)  ==> 초기값이 없다. ==> error

	remove_reference<decltype(*p)>::type  d3;   // int
	// remove_reference<int&>::type  d3;        // int
}
