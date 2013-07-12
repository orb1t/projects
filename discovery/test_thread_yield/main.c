#include <stdio.h>
#include <thread.h>

#define STACK_SIZE  (8192)

char t2_stack[STACK_SIZE];

void second_thread(void) {
    while (1) {
        puts("second thread");
        thread_yield();
    }
}

int main(void)
{
    (void) thread_create(t2_stack, STACK_SIZE, PRIORITY_MAIN, CREATE_WOUT_YIELD | CREATE_STACKTEST, second_thread, "nr2");

    while (1) {
        puts("first thread");
        thread_yield();
    }
}
