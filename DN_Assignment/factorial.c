#include <stdio.h>

int main() {
	int result[256];
	result[0] = 1;
	int digits = 0; //자릿수
	int ceiling = 0; //올림수
	for (int num = 1; num <= 4; num++) {
		for (int idx = 0 ; idx <= digits; idx++) {
			result[idx] = result[idx]*num+ceiling;
			ceiling = result[idx]/10;
			result[idx] %= 10;
		}
		if (ceiling > 0) {
			digits++;
		}
		int idx = 0;
		while (ceiling > 0) {
			ceiling = result[idx]/10;
			result[idx] = result[idx]%10+ceiling;
			idx++;
		}
	}

	for (int i = 0; i<=digits; i++) {
		printf("%d", result[i]);
	}

	return 0;
}
