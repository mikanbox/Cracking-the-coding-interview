#include <cstdio>
#include <cstdlib>
// g++ 2-4.c --sysroot='xcrun --show-sdk-path'

struct Node {
    struct Node *next;
    int data;
};

void print_list_forward_order(struct Node* list)
{
    while(list != NULL) {
        printf("%d, ", list->data);
        list = list->next;
    }
    printf("\n");
}

void print_list_reverse_order(struct Node* list)
{
    int num = 0;
    int c=1;
    while(list != NULL) {
        num += list->data * c;
        list = list->next;
        c *= 10;
    }
    printf("%d, ", num);
    printf("\n");
}

struct Node* new_list_sum_of_lists(struct Node* list1, struct Node* list2){
    struct Node* sum_list;
    struct Node* itr = NULL;
    struct Node* itr_prev = NULL;
    int carry =0;


    while(list1 != NULL || list2 != NULL){
        itr = (struct Node*)malloc(sizeof(struct Node));
        if (itr_prev == NULL)
            sum_list = itr;

        itr->data = carry;
        carry = 0;
        
        if (list1 != NULL){
            itr->data += list1->data;
            list1 = list1 -> next;
        }
        
        if (list2 != NULL){
            itr->data += list2->data;
            list2 = list2 -> next;
        }
        
        if (itr->data > 10) {
            itr->data -= 10;
            carry = 1;
        }
        printf("%d, ", itr->data);
        
        if (itr_prev != NULL)
            itr_prev->next = itr;
        itr_prev = itr;
    }


    return sum_list;
}


int main(void) {
    struct Node num1[3];
    num1[0].data = 7;
    num1[0].next = &num1[1];
    num1[1].data = 1;
    num1[1].next = &num1[2];
    num1[2].data = 6;
    num1[2].next = NULL;

    struct Node num2[3];
    num2[0].data = 5;
    num2[0].next = &num2[1];
    num2[1].data = 9;
    num2[1].next = &num2[2];
    num2[2].data = 2;
    num2[2].next = NULL;

    print_list_forward_order(num1);
    print_list_forward_order(num2);

    print_list_reverse_order(num1);
    print_list_reverse_order(num2);


    struct Node* res = new_list_sum_of_lists(num1,num2);

    print_list_reverse_order(res);


    return 0;
}
