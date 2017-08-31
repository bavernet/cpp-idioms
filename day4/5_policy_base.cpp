// 5_policy_base - 183 page (교재는 policy clone)
#include <iostream>
using namespace std;

class NoLock;

template <typename T, typename ThreadModel=NoLock>
struct List {
	ThreadModel tm;
	void push_front(const T& a) {
		tm.lock();
		tm.unlock();
	}
};

struct NoLock {
	inline void lock() {}
	inline void unlock() {}
};

struct PosixLock {
	// pthread_mutex pm;
	inline void lock()   { cout << "lock" << endl; }
	inline void unlock() { cout << "unlock" << endl; }
};

List<int> s;    // 전역변수.. 멀티스레드에 안전하지 않다.

int main() {
	s.push_front(10);
}
