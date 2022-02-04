#include <stdio.h>
#include <limits.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do 
    putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
  printf("\n");
}

int main(void) {

    // 32 bit integer
    int n = 29;
    int m = 15;
    int x = n ^ m;
    printb(x);
    printf("\n");

    int mask[10];
    mask[0] = 0x55555555;
    mask[1] = 0xAAAAAAAA;
    mask[2] = 0x33333333;
    mask[3] = 0xCCCCCCCC;
    mask[4] = 0x0F0F0F0F;
    mask[5] = 0xF0F0F0F0;
    mask[6] = 0x00FF00FF;
    mask[7] = 0xFF00FF00;
    mask[8] = 0x0000FFFF;
    mask[9] = 0xFFFF0000;


    for (int i = 0; i < 5; i++) {
        x = ((x & mask[i * 2 + 1]) >> (1 << i)) + (x & mask[i * 2]);
        printb(x);
    }
    
    printf("%d\n", x);

    return 0;
};