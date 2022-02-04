#include <stdio.h>



void solution(double input) {
    double tmp = 1.0;

    for (int i = 0; i < 32; i++) {
        if (input >= tmp) {
            printf("1");
            input -= tmp;
        } else {
            printf("0");
        }
        tmp /= 2;
    }

    if (input == 0) {

    } else {
        printf("\r                                \rERROR\n");
    }

}


int main(void) {

    double input = 0.75;

    // printf(input);
    printf("input:%f \n",input);

    solution(input);

    return 0;
};