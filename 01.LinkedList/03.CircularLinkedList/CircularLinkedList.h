#define data_t int

struct Node {
    data_t data;
    struct Node* next;
    struct Node* prev;
};

struct CircularLinkedList {
    struct Node* head;
    struct Node* tail;
    int size_of_list;
};

struct CircularLinkedList* init_list(void);
void insert_head(struct CircularLinkedList* list, data_t data);
void insert_pos(struct CircularLinkedList* list, data_t pos_data, data_t data);
int find_data(struct CircularLinkedList* list, data_t search_data);
void delete_data(struct CircularLinkedList* list, data_t search_data);
void print_all_data_twice(struct CircularLinkedList* list);
int get_size_of_list(struct CircularLinkedList* list);
void delete_list(struct CircularLinkedList* list);