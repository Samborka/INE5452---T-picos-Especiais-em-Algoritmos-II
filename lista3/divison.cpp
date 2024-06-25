	#include <cstdio>
	#include <set>
	#include <utility>
	#include <cmath>
	#include <iostream>
	using namespace std;

	bool hasUniqueDigits(int num1, int num2) {
		if (num1 >= 100000)
			return false;

		int digit, mask = 0;
		for (int i = 0; i < 5; i++) {
			digit = (int)(num1 / pow(10, i)) % 10;
			if ((mask >> digit) % 2)
				return false;
			mask |= 1 << digit;
		}
		for (int i = 0; i < 5; i++) {
			digit = (int)(num2 / pow(10, i)) % 10;
			if ((mask >> digit) % 2)
				return false;
			mask |= 1 << digit;
		}

		return true;
	}

	int main() {
		int n, count = 0;

		while (scanf("%d", &n), n) {
			int numerator, denominator;
			bool found = false;
			count++;
			if (count > 1)
				printf("\n");

			for (denominator = 1234; denominator < 50000; denominator++) {
				numerator = denominator * n;
				if (hasUniqueDigits(numerator, denominator)) {
					printf("%05d / %05d = %d\n", numerator, denominator, n);
					found = true;
				}
			}
			if (!found)
				printf("There are no solutions for %d.\n", n);
		}

		return 0;
	}