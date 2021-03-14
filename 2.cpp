#include <iostream>
#include <stdlib.h>




// Function takes any given number N and sums it's digits by taking mod(10) to give us last digit and then divide by 10 to get digit on next
// most significant position. After we've obtained all digits(last digit must be be smaller than 10) we check if digit's sum is prime by
// looking for it's factors.
bool CheckNumber(int N) {
	int backup = N;
	int sum = 0;

	while (N > 10) {
		sum += N % 10;
		N /= 10;
	}
	sum += N;
	backup /= sum;
	bool isPrime = true;
	if (backup == 0 || backup == 1) {
		isPrime = false;
	}
	else {
		for (int i = 2; i <= backup / 2; ++i) {
			if (backup % i == 0) {
				isPrime = false;
				break;
			}
		}
	}
	if (isPrime)
		return true;
	else
		return false;



}

int main() {
	//CheckNumber(554);
	std::cout << CheckNumber(43) << std::endl;
	return 0;

}