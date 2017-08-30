#include <iostream>
using namespace std;;

class Animal {
};
ostream &operator <<(ostream &os, const Animal &a) {
	return os << "Animal";
}

class Dog : public Animal {};
ostream &operator <<(ostream &os, const Dog &a) {
	return os << "Dog";
}

int main(void) {
	Animal a;   cout << a << endl;
	Dog b;   cout << b << endl;

	Animal *p = &b;
	cout << (*p) << endl;
}
