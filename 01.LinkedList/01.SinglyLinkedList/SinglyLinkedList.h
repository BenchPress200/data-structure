#define data_t int

struct Node {
    data_t data;
    struct Node* next;
};

struct SinglyLinkedList {
    struct Node* head;
    int size_of_list;
};

struct SinglyLinkedList* init_list(void);
void insert_head(struct SinglyLinkedList* list, data_t data);
void insert_pos(struct SinglyLinkedList* list, data_t pos_data, data_t data);
int find_data(struct SinglyLinkedList* list, data_t search_data);
void delete_data(struct SinglyLinkedList* list, data_t search_data);
void print_all_data(struct SinglyLinkedList* list);
int get_size_of_list(struct SinglyLinkedList* list);
void delete_list(struct SinglyLinkedList* list);