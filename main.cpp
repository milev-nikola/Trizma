#include <iostream>
#include <algorithm>

unsigned SIZE = 0;

bool compare(long long a, long long b) {
	return a > b;
}



long long PerfectSquare(long long array[]) {

	for (unsigned i = 0; i < SIZE/2; i++) {
		// If square root of number is not an integeer value, that number is the one we are looking for
		// because we have previously sorted our array in decending order. 
		//First number to have fractional part is the number we are looking for
		double temp = std::sqrt(array[i]);
		double temp_1;
		// std::modf returns fractional part of number
		double t_temp = std::modf(temp, &temp_1);
		if (t_temp != 0) {
			return array[i];
			break;
		}
	}
	return 0;

}



void main() {
	long long array[] = { 1, 2, 4, 8, 16, 32, 64, 576};

	// Array's lenght
	SIZE = sizeof(array) / sizeof(array[0]);
	// Sorting array in decending order, because we are sure to find the largest non-perfect square number starting from the largest
	// Worst case would be if we had an array of same non-perfect square numbers, such as {32, 32, 32, 32}
	std::sort(array, array + SIZE, compare);

	std::cout << PerfectSquare(array) << std::endl;

}