#include <stdio.h>

void check(int x) {
    if (x > 10) {
        printf("Large: %d\n", x);
    } else {
        printf("Small: %d\n", x);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        check(i * 5);
    }
    return 0;
}

