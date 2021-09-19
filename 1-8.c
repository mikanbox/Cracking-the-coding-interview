#include <stdio.h>
// g++ 1-7.c --sysroot=`xcrun --show-sdk-path`

void pretty_print(int* a, const int m, const int n)
{
    // **a は *(*a)の(*a)のサイズが3であることを知らないため、うまく切り出せない ? 
    for (int i = 0; i < m; ++i) {      
        printf("[ ");  
        for(int j = 0; j < n; ++j) {            
            printf ("%d, ", *(a + i * n + j));
        }
        printf ("]\n");
    }
}

// 愚直会
void solution(int* matrix, int m, int n)
{

    for (int i = 0; i < m; ++i) {        
        for(int j = 0; j < n; ++j) { 
            if (matrix[i * n + j] == 0){
                for (int k = 0; k < m; ++k) 
                    matrix[k * n + j] = -1;
                for (int l = 0; l < n; ++l) 
                    matrix[i * n + l] = -1;
                printf("%d,%d : ",i,j);
            } 
        }
    }
        for (int i = 0; i < m; ++i) {        
        for(int j = 0; j < n; ++j) { 
            if (matrix[i * n + j] == -1)
                matrix[i * n + j] = 0;
        }
    }
}


int main(void){

    int matrix[4][3] = {
        {1, 2, 3 },
        {4, 5, 6 },
        {7, 8, 0 },
        {10, 11, 12 }
    };


    pretty_print((int*) matrix, 4,3);

    solution((int*) matrix, 4, 3 );

    printf("\n");

    pretty_print((int*) matrix, 4,3);

    return 0;
}