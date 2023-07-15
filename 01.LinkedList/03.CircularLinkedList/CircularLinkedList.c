#include "CircularLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct CircularLinkedList* init_list(void) {
    struct CircularLinkedList* list = (struct CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size_of_list = 0;

    return list;
    
}

void insert_head(struct CircularLinkedList* list, data_t data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if(list->size_of_list == 0) {
        list->head = new_node;
        list->tail = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;

        new_node->prev = list->tail;
        list->tail->next = new_node;
    }
        list->size_of_list++;

    
}

void insert_pos(struct CircularLinkedList* list, data_t pos_data, data_t data) {

    if(!find_data(list, pos_data)) {
        printf("pos_data: %d don't existed\n", pos_data);
        return;
    }


    struct Node* search_node = list->head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    

    while(search_node != NULL) {

        if(search_node->data == pos_data) {
            
            new_node->next = search_node->next;
            search_node->next->prev = new_node;
            new_node->prev = search_node;
            search_node->next = new_node;

            if(search_node == list->tail) 
                list->tail = new_node;

            list->size_of_list++;
            return;
        }
        
        search_node = search_node->next;
    }



    printf("pos_data: %d don't existed\n", pos_data);

}

int find_data(struct CircularLinkedList* list, data_t search_data) {

    struct Node* search_node = list->head;

    for(int i = 0; i < list->size_of_list; i++) {
        if(search_node == NULL)
            return 0;

        if(search_node->data == search_data)
            return 1;
        search_node = search_node->next;
    }

    return 0;

}

void delete_data(struct CircularLinkedList* list, data_t search_data) {

    struct Node* delete_node = NULL;
    struct Node* search_node = list->head;

    for(int i = 0; i < list->size_of_list; i++) {
        if(search_node->data == search_data) {
                delete_node = search_node;
                search_node->prev->next = search_node->next;
                search_node->next->prev = search_node->prev;

            if(search_node == list->head) 
                list->head = search_node->next;
            else if(search_node == list->tail) 
                list->tail = search_node->prev;
            
            list->size_of_list--;
            free(delete_node);
            return;
        }
            search_node = search_node->next;
    }


}

void print_all_data_twice(struct CircularLinkedList* list) {

    struct Node* search_node = list->head;

    int i = 0;
    while(i < list->size_of_list * 2) {
        printf("%d ", search_node->data);
        search_node = search_node->next;
        i++;
    }
    printf("\n");


}

int get_size_of_list(struct CircularLinkedList* list) {
    return list->size_of_list;
}

void delete_list(struct CircularLinkedList* list) {

    struct Node* delete_node = NULL;
    struct Node* search_node = list->head;
    for(int i = 0; i < list->size_of_list; i++) {
        delete_node = search_node;
        search_node = search_node->next;
        free(delete_node);
    }
    free(list);
}