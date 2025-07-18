#include <stdio.h>

int main_4096(void) {
    for (int line = 0; line < 8; line++) {
        for (int col = 0; col < 8; col++) {
            for (int block = 0; block < 8; block++) {
                for (int row = 1; row <= 8; row++) {
                    printf("%5d", row + (col * 8) + (block * 8*8) + (line * 8*8*8));
                }
                printf(" |");
            }
            printf("\n");
        }
        printf("\n");
    }
}
