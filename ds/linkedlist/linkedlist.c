#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
struct Node {
    Node* next;
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

void linkedListAppend(LinkedList* list, int data)
{
    // If list is empty
    if(list->head == NULL){
        list->head = newNode(data);
        return;
    }

    // Traverse the linked list, find the last node
    Node* current = list->head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    // 'current' now points to the tail node, update it
    current->next = newNode(data);
}


int linkedListSearch(LinkedList* list, int data)
{
    // If list is empty
    if(list->head == NULL){
        return -1; // Not found
    }

    // Traverse the linked list, find node that contains the data
    Node* current = list->head;
    int currentIndex = 0;
    while(current != NULL && current->data != data)
    {
        current = current->next;
        currentIndex++;
    }

    // Searched through entire list, didnt find data
    if(current == NULL) return -1;
    
    return currentIndex;

}

void linkedListDelete(LinkedList* list, int index)
{
    // If list is empty
    if(list->head == NULL) return;

    // Deleting head, update head to next node
    if(index == 0)
    {
        Node* head = list->head;
        list->head = list->head->next;
        free(head);
        return;
    }

    // Traverse the linked list
    // Find the node before the to be deleted node
    Node* current = list->head;
    int currentIndex = 0;
    int prevNodeIndex = index - 1;
    while(current != NULL && currentIndex < prevNodeIndex)
    {
        current = current->next;
        currentIndex += 1;
    }

    // Got to end of the list before the index
    if(current == NULL) return;

    Node* delete = current->next;
    current->next = delete->next; // Or current->next->next
    free(delete);
}

void linkedListPrint(LinkedList* list)
{
    // If list is empty
    if(list->head == NULL){
        printf("Linked List is empty\n");
        return;
    }

    // Traverse the linked list, find the last node
    Node* current = list->head;
    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}



int main(){
    LinkedList list;
    newLinkedList(&list);

    linkedListAppend(&list, 1);
    linkedListAppend(&list, 2);
    linkedListAppend(&list, 3);

    int index = linkedListSearch(&list, 2);
    printf("Found at index: %d\n", index);
    
    linkedListPrint(&list);
    linkedListDelete(&list, 3);
    linkedListPrint(&list);
    


}