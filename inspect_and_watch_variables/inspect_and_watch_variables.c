#include <stdio.h>

void math(int x, int y) {
    int sum = x + y;
    int diff = x - y;
    int prod = x * y;
    printf("Sum: %d, Diff: %d, Prod: %d\n", sum, diff, prod);
    for(int i=0;i<5;i++)
        printf("%d\n",i);
}

int main() {
    math(7, 3);
    return 0;
}

