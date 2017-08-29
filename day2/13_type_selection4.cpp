#include <iostream>
#include <type_traits> // C++11부터 제공되는 헤더
using namespace std;

template <int N>
struct Bitset {
    static_assert(N <= 32, "Error: N must be less than 32");
    typedef typename conditional<(N <= 8),char,
            typename conditional<(N <= 16),short,int>::type>::type TYPE;
    TYPE data;
};

#define show(a) cout << #a << " = " << a << endl

int main(void) {
    Bitset<8> b1;
    Bitset<32> b2;
    Bitset<16> b3;
    Bitset<100> b4;

    show(sizeof(b1));   // 1
    show(sizeof(b2));   // 4
    show(sizeof(b3));   // 2
}
