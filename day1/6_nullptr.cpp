// nullptr 교재 - 173 page
#include <iostream>
using namespace std;

void foo(void *p) { cout << "void*" << endl; }  // 1
void foo(int n)   { cout << "int" << endl; }    // 2

void goo(char *p) { cout << "char*" << endl; }

int main(void) {
	int n = 0;
	int *p1 = 0;  // ok. 0은 정수지만 포인터로 암시적 형변환이 된다
	//int *p2 = 10; // error
	foo(0);   // 2
	foo((void*)0); // 1

// c++ 컴파일러의 NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    (void*)0
#endif

	foo(NULL);
	goo(NULL);  // C   : void* ==> char* 암시적 형변환 가능
				// C++ : void* ==> char* 암시적 형변환 안됨
}
