#include <iostream>
#include "Bitset.h"
#include <cmath>

int main() {
		Bitset bit(256);
		bit.set(5);
		bit.set(7);
		bit.unset(5);
		bit.print();
}
