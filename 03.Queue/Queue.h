#define data_t int

typedef struct Node {
    data_t data;    
    struct Node* next;
}Node;

typedef struct Queue {
    int size;
    struct Node* head;
}Queue;

Queue* init_queue(void);
void enqueue(Queue* q, data_t data);
data_t dequeue(Queue* q);
data_t peek(Queue* q);
int isEmpty(Queue* q);
void delete_queue(Queue* q);
int get_size(Queue* q);
