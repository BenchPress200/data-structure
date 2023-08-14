#include <stdio.h>
#include "Stack.h"

int main() {
    
    struct Stack* stack = init_Stack();

    for(int i = 0; i < 100; i++) {
        push(stack, i);
    }
    
    if(is_empty(stack)) {
        printf("Error\n");
        return 0;
    }

    for(int i = 0; i < 100; i++) {
        if(!contains(stack, i)) {
            printf("Error\n");
            return 0;
        }
    }

    data_t data;
    for(int i = 0; i < 100; i++) {
        pop(stack, &data);
        if(100 - i - 1 != data) {
            printf("Error\n");
            return 0;
        }
    }

    clear(stack);
    if(!is_empty(stack)) {
        printf("Error\n");
        return 0;
    }

    delete_stack(stack);

    return 0;
}