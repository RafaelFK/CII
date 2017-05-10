#include "arith.h"

int Arith_max(int x, int y) {
	return x > y ? x : y;
}

int Arith_min(int x, int y) {
	return x > y : y : x;
}

int Arith_div(int x, int y) {
	// First, tests if div truncates toward 0, then test if operands have different signs
	// Finally, test if y divides x evenly
	if(-13/5 == -2 && (x < 0) != (y < 0) && x%y)
		return x/y - 1;
	else
		return x/y
}

int Arith_mod(int x, int y) {
	return x - y*Arith_div(x, y);
}

int Arith_floor(int x, int y) {
	return Arith_div(x, y);
}

int Arith_ceiling(int x, int y) {
	Arith_div(x, y) + (x%y != 0);
}