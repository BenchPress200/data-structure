#include "CircularLinkedList.h"
#include <stdio.h>

int main() {

    struct CircularLinkedList* list = init_list();

    insert_head(list, 9);
    insert_head(list, 8);
    insert_head(list, 7);
    insert_head(list, 6);
    print_all_data_twice(list);

    insert_pos(list, 6, 10);
    print_all_data_twice(list);

    insert_pos(list, 8, 50);
    insert_head(list, 88);
    print_all_data_twice(list);
      



    delete_list(list);
    return 0;

}