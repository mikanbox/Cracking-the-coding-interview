#include <cstdio>
#include <cstdlib>
// g++ 2-6.c --sysroot=`xcrun --show-sdk-path`

typedef struct Node {
    struct Node *next;
    int data;
} NODE;


void print_list_forward_order(NODE *list) {
    while(list != NULL) {
        printf("%d, ", list->data);
        list = list->next;
    }
    printf("\n");
}

// 愚直解はlistと同じサイズのリスト用意し、スタックのようにノードを積んでいく
// もしくは、NULLになるまで再帰する
bool IsPalindrome(NODE *list) {
    bool ans = false;
    NODE *p = list;

    if (list -> next == NULL) 
        return true;
    list = list -> next;

    while(list != NULL){

    }

    return ans;
}


int main(void) {
    NODE num1[5];
    num1[0].data = 7;
    num1[0].next = &num1[1];
    num1[1].data = 1;
    num1[1].next = &num1[2];
    num1[2].data = 2;
    num1[2].next = &num1[3];
    num1[3].data = 1;
    num1[3].next = &num1[4];
    num1[4].data = 6;
    num1[4].next = NULL;


    print_list_forward_order(num1);






    return 0;
}
