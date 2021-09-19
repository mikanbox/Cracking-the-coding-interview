#include <stdio.h>
// g++ 1-7.c --sysroot=`xcrun --show-sdk-path`

void printimage( int* a, const int image_size ) {
    for (int i = 0; i < image_size; ++i) {
        printf("[");
        for(int j = 0; j < image_size; ++j) {
            printf ("%2d, ", a[i * image_size * 4 + j * 4] );
            // printf ("%d: ", a[i * image_size * 4 + j * 4 + 1] );
            // printf ("%d: ", a[i * image_size * 4 + j * 4+ 2] );
            // printf ("%d: ", a[i * image_size * 4 + j * + 3] );
        }
        printf ("]\n");
    }
}

void swappixel(int* a, int* b ) {
    for (int i = 0; i < 4; ++i) {
        int c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
}

void solution( int* a , const int image_size ) {

    // strategy
    // rotate First quadrant
    // int half_image_size = + image_size / 2 + image_size % 2;

    for (int i = 0; i < image_size - 1; ++i) {
        for (int j = i; j < image_size - 1 - i; ++j) {
            int i_from = i, j_from = j;
            for (int k = 0; k < 3; ++k) {
                int i_to = j_from;
                int j_to = image_size - 1 - i_from;
                // printf(" ( %d , %d ) swap ( %d , %d ) \n",i_from, j_from , i_to , j_to );
                swappixel(&a[i_from * image_size * 4 + j_from * 4] , &a[ i_to * image_size * 4 + j_to * 4]);
                i_from = i_to;
                j_from = j_to;
            }
        }
    }
};

// 1 2 3 4 5
// 2 3 4 5 6
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0

// 1 2 3 4 5
// x x 4 x x
// x x 0 x x


int main(void){

    // int image[2][2][4] = {
    //     {
    //         {
    //             0,0,0,0
    //         },
    //         {  
    //             1,1,1,1
    //         }
    //     },
    //     {
    //         {
    //             2,2,2,2
    //         },
    //         {
    //             3,3,3,3
    //         }
    //     }
    // };

    // int image[3][3][4] = {
    //     {
    //         {
    //             0,0,0,0
    //         },
    //         {  
    //             1,1,1,1
    //         },
    //         {
    //             2,2,2,2
    //         }
    //     },
    //     {
    //         {
    //             3,3,3,3
    //         },
    //         {
    //             4,4,4,4
    //         },
    //         {
    //             5,5,5,5
    //         }
    //     },
    //     {
    //         {
    //             6,6,6,6
    //         },
    //         {
    //             7,7,7,7
    //         },
    //         {
    //             8,8,8,8
    //         }
    //     }
    // };

    int image[4][4][4] = {
        {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}},
        {{5,5,5,5},{6,6,6,6},{7,7,7,7},{8,8,8,8}},
        {{9,9,9,9},{10,2,2,2},{11,3,3,3},{12,4,4,4}},
        {{13,1,1,1},{14,2,2,2},{15,3,3,3},{16,4,4,4}}
    };


    printimage((int*)image, 4);

    // swappixel(image[0][0],image[1][1]);

    // printimage((int*)image, 2);

    printf("\n");

    solution( (int*)image , 4 );

    printimage((int*)image, 4);


    return 0;
}
