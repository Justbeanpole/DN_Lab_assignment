#include <stdio.h>

int main_4096(void) {
    for (int l = 0; l < 8; l++) {
        for (int k = 0; k < 8; k++) {
            for (int i = 0; i < 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    printf("%5d", j + (k * 8) + (i * 8*8) + (l * 8*8*8));
                }
                printf(" |");
            }
            printf("\n");
        }
        printf("\n");
    }
}
