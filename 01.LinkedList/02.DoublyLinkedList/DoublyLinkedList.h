#define data_t int

struct Node {
    data_t data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLinkedList {
    struct Node* head;
    int size_of_list;
};

struct DoublyLinkedList* init_list(void);
void insert_head(struct DoublyLinkedList* list, data_t data);
void insert_pos(struct DoublyLinkedList* list, data_t pos_data, data_t data);
int find_data(struct DoublyLinkedList* list, data_t search_data);
void delete_data(struct DoublyLinkedList* list, data_t search_data);
void print_all_data_twice(struct DoublyLinkedList* list);
int get_size_of_list(struct DoublyLinkedList* list);
void delete_list(struct DoublyLinkedList* list);