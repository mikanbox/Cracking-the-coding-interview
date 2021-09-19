#include <cstdio>
#include <cstdlib>
// g++ 2-4.c --sysroot=`xcrun --show-sdk-path`

//  3 - 5 - 8 - 5 - 10 - 2 - 1
//  3 - 1 - 2 - 10 - 5 - 5  - 8 

// 愚直
// リスト二つ用意して 5 未満 5 以上の要素をそれぞれ分けて入れてく O(n) , 空間(n)

// ほか
// 3 - 5 - 8 - 5 - 10 - 2 - 1



struct Node {
    int data;
    Node *next;
    // Node *prev;
};

void pretty_print(struct Node *list) {

    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("\n");
}


struct Node *partition_list(struct Node *list, int x) {
    struct Node *head = list;
    struct Node *prev;

    if (head == NULL)
        return head;

    list = list->next;
    if (list == NULL)
        return head;

    prev = head;


//  3 - 5 - 8 - 5 - 10 - 2 - 1

    while (list != NULL) {
        struct Node *next = list->next;

        if (list->data < x) {
            list->next = head;
            head = list;
            prev->next = next;
        } else {
            prev = prev->next;
        }
        
        list = next;
    }

    return head;
}



int main(void) {

    struct Node input[7];
    for (int i = 0; i < 6; i++ ) {
        input[i].next = &input[i + 1];
    }
    input[6].next=NULL;

    input[0].data = 3;
    input[1].data = 5;
    input[2].data = 8;
    input[3].data = 5;
    input[4].data = 10;
    input[5].data = 2;
    input[6].data = 1;

    pretty_print(&input[0]);

    // struct Node *partitioned_list = partition_list(&input[0], 12);
    // struct Node *partitioned_list = partition_list(NULL, 12);

    struct Node input2;
    input2.data = 1;
    input2.next = NULL;
    struct Node *partitioned_list = partition_list(&input2, 12);

    pretty_print(partitioned_list);


    return 0;
}
