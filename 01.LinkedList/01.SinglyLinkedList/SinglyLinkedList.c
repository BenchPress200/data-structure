#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

struct SinglyLinkedList* init_list(void) {
    struct SinglyLinkedList* list = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
    list->head = NULL;
    list->size_of_list = 0;
    return list;
}

void insert_head(struct SinglyLinkedList* list, data_t data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size_of_list++;
}

void insert_pos(struct SinglyLinkedList* list, data_t pos_data, data_t data) {

    if(!find_data(list, pos_data)) {
        printf("pos_data does not exist\n");
        return;
    }

    struct Node* search_node = list->head;

    while(search_node != NULL) {
        if(search_node->data == pos_data) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->next = search_node->next;
            search_node->next = new_node;
            list->size_of_list++;
            return;
        }
        search_node = search_node->next;
    }

    printf("pos_data does not exist\n");

}

int find_data(struct SinglyLinkedList* list, data_t search_data) {

    struct Node* search_node = list->head;

    while(search_node != NULL) {
        if(search_node->data == search_data)
            return 1;

        search_node = search_node->next;
    }
    return 0;
}

void delete_data(struct SinglyLinkedList* list, data_t search_data) {
    struct Node* prev_node = NULL;
    struct Node* search_node = list->head;

    while(search_node != NULL) {
        if(search_node->data == search_data) {
            if(prev_node == NULL) {
                list->head = search_node->next;
                list->size_of_list--;
                free(search_node);
                return;
            }
            prev_node->next = search_node->next;
            list->size_of_list--;
            free(search_node);
            return;
        }
            
        prev_node = search_node;
        search_node = search_node->next;
    }

    printf("search_data does not exist\n");
}

void print_all_data(struct SinglyLinkedList* list) {

    struct Node* search_node = list->head;

    while(search_node != NULL) {
        printf("%d ", search_node->data);
        search_node = search_node->next;
    }
    printf("\n");

}

int get_size_of_list(struct SinglyLinkedList* list) {
    return list->size_of_list;
}

void delete_list(struct SinglyLinkedList* list) {

    struct Node* delete_node = NULL;
    struct Node* search_node = list->head;

    while(search_node != NULL) {
        delete_node = search_node;
        search_node = search_node->next;
        free(delete_node);
    }
}