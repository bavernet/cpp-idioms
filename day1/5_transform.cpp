// 5 변환 - 다양한 기법을 이해하려면 반드시 알아야 합니다
struct Point {
	int x = 1, y = 2;

	// 변환 연산자: 객체를 다른 타입으로 변환되게 한다
	// 특징: 리턴타입을 표기하지 않는다.
	operator int() { return y; }
};

int main(void) {
	Point pt;
	int n1 = pt; // ok. 암시적 변환도 가능
	int n2 = static_cast<int>(pt); // 컴파일러는 pt.operator int()를 찾게 된다.
}
