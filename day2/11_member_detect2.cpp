// 11_MemberDetect - 143 page - 아주 어렵습니다

#include <iostream>
#include <vector>
using namespace std;

// 2단계. 클래스와 typedef
// STL의 다양한 컨테이너에는 멤버로 typedef가 많이 있다
#if 0
template <typename T>
class vector {
public:
	typedef unsigned int size_type;
};
#endif

int main() {
	vector<int> v(10, 3);
	// int sz = v.size();
	vector<int>::size_type sz = v.size();   // 가장 좋은 코드
}
