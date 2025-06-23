#include <stdio.h>

void greet() {
    int a = 5,b=7;
    printf("Sum: %d\n",a+b);
}

int main() {
    greet();
    printf("Back in main.\n");
    return 0;
}
