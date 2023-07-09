#include <stdio.h>
#include "SinglyLinkedList.h"

int main() {

    struct SinglyLinkedList* list = init_list();

    insert_head(list, 1);
    insert_pos(list, 4, 5);
    insert_pos(list, 1, 5);
    insert_head(list, 9);

    // 9, 1, 5
    print_all_data(list);

    insert_head(list, 10);
    insert_head(list, 12);
    insert_head(list, 16);

    // 16, 12, 10, 9, 1, 5
    print_all_data(list);

    delete_data(list, 10);
    delete_data(list, 20);

    // 16, 12, 9, 1, 5
    print_all_data(list);


    return 0;
}