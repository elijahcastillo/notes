#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
struct Node {
    Node* next;
    Node* prev;
    int data;
};

typedef struct {
    Node* head;
} LinkedList;


void newLinkedList(LinkedList* list)
{
    list->head = NULL;
}

Node* newNode(int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}



int main(){
    


}