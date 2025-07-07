#include "user/user.h"

#define STACK_SIZE 100

void *my_thread(void *arg) {
    uint64 number = (uint64)arg;
    for(int i = 0; i < 5; ++i) {
        printf("Thread %d: count %lu\n", i, number++);
    }
    return 0;
}

int main() {
    int stack[STACK_SIZE];
    int tid = thread(my_thread, stack+STACK_SIZE, (void*)100);
    printf("Thread ID: %d\n", tid);
    jointthread(tid);
    printf("Done\n");
    exit(0);
}
