#include <stdio.h>
#include "Queue.h"
#define NUM_DATA 1000

int main() {

    Queue* queue = init_queue();
    for(int i = 0; i < NUM_DATA; i++) 
        enqueue(queue, i);

    if(get_size(queue) != NUM_DATA) {
        printf("error\n");
        return 0;
    }

    for(int i = 0; i < NUM_DATA; i++) {
        if(peek(queue) != i) {
            printf("error\n");
            return 0;
        }

        if(dequeue(queue) != i) {
            printf("error\n");
            return 0;
        }

        if(get_size(queue) != NUM_DATA - i - 1) {
            printf("error\n");
            return 0;
        }

    }

    delete_queue(queue);

    return 0;
}