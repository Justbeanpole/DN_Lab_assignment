#include <stdio.h>
void printRow(int lv, int star);

int main_diamond() {
    int input = 0;
    printf("숫자를 입력하시오 :");
    scanf("%d", &input);
    int start = input % 2 == 0 ? 2 : 1;
    for (int star = start; star <= input; star += 2) {
        printRow(input, star);
    }
    for (int star = input-2; star > 0; star -= 2) {
        printRow(input, star);
    }
    return 0;
}

void printRow(int lv, int star) {
    int space = (lv-star)/2;
    for (int s = 0; s < space; s++) { printf(" "); }
    for (int row = 0; row < star; row++) { printf("*"); }
    printf("\n");
}