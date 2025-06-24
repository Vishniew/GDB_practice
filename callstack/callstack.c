#include <stdio.h>

void third(int z) {
    printf("Inside third. z = %d\n", z);
}

void second(int y) {
    third(y + 5);
}

void first(int x) {
    second(x + 10);
}

int main() {
    first(3);
    return 0;
}
