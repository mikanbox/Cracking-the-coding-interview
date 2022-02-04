#include <stdio.h>


void toBinary(int x, int *strips, int size) {
    for (int i = 0; i < 10; i++) 
        if ((x & (1 << i)) > 0)
            strips[i] = 1;
}

void toDecimal(int *strips, int *x, int size) {
    x = 0;
    for (int i = 0; i < 10; i++)
        x += strips[i] * (1 << i);
} 



int main(void) {
    int x;
    scanf("%d",&x);

    int strips[10];
    for (int i = 0; i < 10; i++) 
        strips[i] = 0;
    // x -> 
    toBinary(x, strips, 10);
    for (int i = 9; i >= 0; i--) 
        printf("%d",strips[i]);
    printf("\n");


    toDecimal(strips, &x, 10);
    printf("%d\n", x);

    return 0;
}