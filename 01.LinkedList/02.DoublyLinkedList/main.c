#include "DoublyLinkedList.h"
#include <stdio.h>


int main() {

    struct DoublyLinkedList* list = init_list();

    insert_head(list, 15);
    insert_head(list, 5);
    insert_head(list, 7);
    insert_pos(list, 15, 9);
    insert_pos(list, 25, 9);
    print_all_data_twice(list);
    

    insert_pos(list, 9, 88);
    insert_head(list, 1);
    insert_head(list, 45);
    insert_head(list, 99);
    print_all_data_twice(list);

    delete_data(list, 88);
    delete_data(list, 5);
    print_all_data_twice(list);



    delete_list(list);

    return 0;
}