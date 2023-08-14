#include <stdlib.h>
#include "Stack.h"

struct Stack* init_Stack(void) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 0;
    stack->head = NULL;
    return stack;
}

void push(struct Stack* stack, data_t data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->head;
    stack->head = new_node;

    stack->size++;
}

void pop(struct Stack* stack, data_t* data) {
    struct Node* pop_node = stack->head;
    stack->head = stack->head->next;
    *data = pop_node->data;
    free(pop_node);
    stack->size--;
}

void peek(struct Stack* stack, data_t* data) {
    *data = stack->head->data;
}

int is_empty(struct Stack* stack) {
    if(stack->head == NULL && stack->size == 0)
        return 1;
    else 
        return 0;
}

void clear(struct Stack* stack) {
    
    struct Node* search_node = stack->head;
    struct Node* delete_node;
    while(search_node != NULL) {
        delete_node = search_node;
        search_node = search_node->next;
        free(delete_node);
    }

    stack->size = 0;
    stack->head = NULL;
}

int contains(struct Stack* stack, data_t data) {

    struct Node* search_node = stack->head;

    while(search_node != NULL) {
        if(search_node->data == data)
            return 1;
        search_node = search_node->next;
    }

    return 0;
}

void delete_stack(struct Stack* stack) {
    clear(stack);
    free(stack);
}