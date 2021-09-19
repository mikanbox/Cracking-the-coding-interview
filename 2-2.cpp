#include <stdio.h>
#include <cstdlib>
// g++ 1-7.c --sysroot=`xcrun --show-sdk-path`
// Use After Free

class Node {
public:
    Node* next= nullptr;
    int data;
    
    Node(int d) {
        data= d;
    }
    
    void appendToTail(int d) {
        Node* end = (Node*)malloc(sizeof(Node)) ;
        end->data = d;
        end->next=nullptr;

        Node* n = this;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = end;
    }
};

int main(void) {
    Node a(1);
    a.appendToTail(2);
    a.appendToTail(1);
    a.appendToTail(5);
    a.appendToTail(3);
    a.appendToTail(3);

    return 0;
}



