#include <stdio.h>

int main() {
    int count = 0;

    for (int i = 0; i < 5; i++) {
        count += i;
        printf("i = %d, count = %d\n", i, count);
    }

    return 0;
}
