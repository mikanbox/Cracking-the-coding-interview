#include <stdio.h>
#include <limits.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do 
    putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

int main(void) {

    int n = 1024;
    int m = 19;

    printf("n = ");
    printb(n);
    printf("\n");

    printf("m = ");
    printb(m);
    printf("\n");

    int i = 2;
    int m_digit = 5;


    int mask =  (1 << ( i + 5) ) - (1 << i);

    printf("m = ");
    printb(mask);
    printf("  %d \n",mask);

    int ans = (n & ~mask ) | (m << i);

    printf("a = ");
    printb((n & ~mask ));
    printf("   %d \n" , (n & ~mask ));


    printf("a = ");
    printb(ans);
    printf("\n");

    return 0;
};