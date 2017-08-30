#include <iostream>
using namespace std;

// CRTP를 사용해서 가상함수가 아닌 함수를 가상함수처럼 동작하게 만들기
// MS의 ATL/WTL 라이브러리가 사용하고 있다..

// 모든 윈도우의 기능을 가지는 최상위 클래스 - 템플릿으로 하지 말자
class Window {
};

// CRTP가 필요한 부분만 파생 클래스로
template <typename T>
class MsgWindow: public Window {
public:
	void msgLoop() {     // void msgLoop(Windows* const this)
		// OnClick();    // this->OnClick();
		static_cast<T*>(this)->OnClick();
	}
	void OnClick() { cout << "Window OnClick" << endl; }
};

class MyWindow : public MsgWindow<MyWindow> {
public:
	void OnClick() { cout << "MyWindow OnClick" << endl; }
};

int main(void) {
	MyWindow w;
	w.msgLoop();

	// 기반 클래스 포인터에 자식주소담기는 많이 사용한다.
	Window *p = &w;
	Window *p1 = new OtherWindow;
}
