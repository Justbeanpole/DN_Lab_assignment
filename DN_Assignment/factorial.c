#include <stdio.h>

int main() {
	int result[256]; //결과값
	result[0] = 1; //결과값 초기화
	int digits = 0; //자릿수
	int ceiling = 0; //올림수
	for (int num = 1; num <= 50; num++) { //1~50까지 곱하기
		for (int idx = 0 ; idx <= digits; idx++) {
			result[idx] = result[idx]*num+ceiling; //곱셈 -> 모든 자리에 곱하고 올림수 더하기
			ceiling = result[idx]/10; //올림수 계산
			result[idx] %= 10; //값 계산 후 저장
		}
		while (ceiling > 0) { //올림수가 있다면
			digits++; //자릿수 +1
			result[digits] = ceiling%10; //값 계산 후 저장
			ceiling /= 10; //올림수 계산
		}
	}

	for (int idx = digits; idx>=0; idx--) {
		printf("%d", result[idx]);
	}

	return 0;
}
