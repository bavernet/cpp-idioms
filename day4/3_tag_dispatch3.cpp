#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	list<int> s = { 1, 2, 3 };

	auto p1 = v.begin();
	auto p2 = s.begin();

	p1 = p1 + 2;
	p2 = p2 + 2;
}
