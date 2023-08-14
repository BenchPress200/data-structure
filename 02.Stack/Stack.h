#define data_t int


struct Node {
    data_t data;    
    struct Node* next;
};

struct Stack {
    int size;
    struct Node* head;
};

struct Stack* init_Stack(void);
void push(struct Stack* stack, data_t data);
void pop(struct Stack* stack, data_t* data);
void peek(struct Stack* stack, data_t* data);
int is_empty(struct Stack* stack);
void clear(struct Stack* stack);
int contains(struct Stack* stack, data_t data);
void delete_stack(struct Stack* stack);