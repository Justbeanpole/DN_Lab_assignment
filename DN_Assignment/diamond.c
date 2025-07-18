#include <stdio.h>

int main() {
    int input = 0;
    printf("숫자를 입력하시오 :");
    scanf("%d", &input);
    int even = 0;
    if (input % 2 == 0) {
        even = 1;
    }
    for (int level = input; level > 0; level -= 2) {
        for (int blank = level; blank > 0; blank -= 2) {
            printf(" ");
        }
        for (int star = 0; star <= input - (level - even); star++) {
            printf("*");
        }
        printf("\n");
    }
    for (int level = 2; level < input; level += 2) {
        for (int blank = 0; blank <= level; blank += 2) {
            printf(" ");
        }
        for (int star = 1; star <= input - level; star++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}