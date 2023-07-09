#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

struct DoublyLinkedList* init_list(void) {
    struct DoublyLinkedList* DLL = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    DLL->head = NULL;
    DLL->size_of_list = 0;
    
    return DLL;
}

void insert_head(struct DoublyLinkedList* list, data_t data) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;

    if(list->head != NULL) {
        list->head->prev = new_node;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->size_of_list++;

}

void insert_pos(struct DoublyLinkedList* list, data_t pos_data, data_t data) {

    struct Node* search_node = list->head;

    if(!find_data(list, pos_data)) {
        printf("pos_data does not exist\n");
        printf("inserting %d failed\n", data);
        return;
    }

    while(search_node != NULL) {
        if(search_node->data == pos_data) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;

            new_node->next = search_node->next;
            if(search_node->next != NULL)
                search_node->next->prev = new_node;
            new_node->prev = search_node;
            search_node->next = new_node;
            list->size_of_list++;
            return;
        }

        search_node = search_node->next;
    }

    printf("inserting %d failed\n", data);

}

int find_data(struct DoublyLinkedList* list, data_t search_data) {

    struct Node* search_node = list->head;
    
    while(search_node != NULL) {
        if(search_node->data == search_data) {
            return 1;
        }

        search_node = search_node->next;
    }

    return 0;

}

void delete_data(struct DoublyLinkedList* list, data_t search_data) {

    struct Node* search_node = list->head;

    if(!find_data(list, search_data)) {
        printf("%d does not exist\n", search_data);
        printf("deleting %d failed\n", search_data);
        return;
    }

    while(search_node != NULL) {

        if(search_node->data == search_data) {
            if(search_node->prev != NULL)
                search_node->prev->next = search_node->next;
            if(search_node->next != NULL)
                search_node->next->prev = search_node->prev;
            free(search_node);
            list->size_of_list--;
            return;
        }

        search_node = search_node->next;
    }

    printf("deleting %d failed\n", search_data);

}
void print_all_data_twice(struct DoublyLinkedList* list) {
    
    struct Node* search_node = list->head;

    while(1) {
        printf("%d ", search_node->data);
        if(search_node->next == NULL)
            break;
        search_node = search_node->next;
    }

    printf("\n");
    while(search_node != NULL) {
        printf("%d ", search_node->data);
        search_node = search_node->prev;
    }
    printf("\n");
}

int get_size_of_list(struct DoublyLinkedList* list) {
    return list->size_of_list;
}

void delete_list(struct DoublyLinkedList* list) {

    struct Node* search_node = list->head;
    struct Node* delete_node;

    while(search_node != NULL) {
        delete_node = search_node;
        search_node = search_node->next;
        free(delete_node);
    }

    free(list);
}