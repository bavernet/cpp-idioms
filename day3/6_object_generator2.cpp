#include <tuple>
using namespace std;

int main(void) {
	auto p = make_pair(1, 3.4);
	tuple<int,double,char> t(3, 4.3, 'a');
	auto t2 = make_tuple(3, 4.3, 'a');
}
