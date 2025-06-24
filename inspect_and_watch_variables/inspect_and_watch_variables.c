#include <stdio.h>

void math(int x, int y) {
    int sum = x + y;
    int diff = x - y;
    int prod = x * y;
    printf("Sum: %d, Diff: %d, Prod: %d\n", sum, diff, prod);
    for(int i=0;i<5;i++)
        printf("%d\n",i);
}
void print() {
    int x = 0;
    int y = 0;
    printf("x: %d, y: %d\n", x, y);
}

int main() {
    math(7, 3);
    print();
    return 0;
}

