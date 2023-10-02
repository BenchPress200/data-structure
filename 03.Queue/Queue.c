#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* init_queue(void) {

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;

    return queue;
}

void enqueue(Queue* q, data_t data) {

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(q->head == NULL) {

        q->head = new_node;
        q->size++;

    } else {

        Node* search_node = q->head;

        while(search_node->next != NULL) 
            search_node = search_node->next;
        
        search_node->next = new_node;
        q->size++;

    }
}

data_t dequeue(Queue* q) {
    
    if(isEmpty(q))
        return -1;
    
    data_t ret_val = q->head->data;
    Node* delete_node = q->head;

    q->head = q->head->next;
    free(delete_node);
    q->size--;

    return ret_val;

}

data_t peek(Queue* q) {

    if(isEmpty(q))
        return -1;
    
    return q->head->data;
}

int isEmpty(Queue* q) {
    if(q->head == NULL) {
        printf("Queue is empty \n");
        return 1;
    }
    else 
        return 0;
}

int get_size(Queue* q) {
    return q->size;
}

void delete_queue(Queue* q) {

    Node* search_node = q->head;
    Node* delete_node = NULL;

    if(search_node != NULL) {
        while(search_node->next != NULL) {
            delete_node = search_node;
            search_node = search_node->next;
            free(delete_node);
        }
        free(search_node);
    }
    
    free(q);
}