// 핵심 : 값, 포인터, 참조 캐스팅
// 서로 관련 없는 타입을 reinterpret_cast를 사용할 때
// 값 타입: error
// 포인터, 참조 타입: ok
// 단, 표준 타입의 값 캐스팅은 허용된다. (int <==> double)
struct Point {
	int x, y;
};

struct Pair {
	int first, second;
};

int main(void) {
	Point pt;
	//int n = static_cast<int>(pt); // error
	//int n = reinterpret_cast<int>(pt); // error
	//int* p = reinterpret_cast<int*>(&pt); // ok...
	int &p = reinterpret_cast<int&>(pt); // ok
	return 0;
}
