#include <stdio.h>
#include <thread.h>
#include <hwtimer.h>
#include <vtimer.h>

void second_thread(void) {
    printf("second_thread starting.\n");
    msg_t m;
    int i;

    while(1) {
        msg_receive(&m);

        printf("Processing...");

        for(i = 1680000; i > 0; i--);

        puts(" End\n");
    }
}

char second_thread_stack[KERNEL_CONF_STACKSIZE_MAIN];

int main(void)
{
    unsigned long time = 1000000;

    puts("Initializing timer...");
    msg_t m;

    int pid = thread_create(second_thread_stack, sizeof(second_thread_stack), PRIORITY_MAIN, CREATE_WOUT_YIELD | CREATE_STACKTEST, second_thread, "pong");  puts("initializing timer...");

    hwtimer_init();
    vtimer_init();

    puts("Initializing timer [OK].");

    while (1) {
        printf("Sleep for %ld\n\n", time);

        vtimer_usleep(time);

        puts("Wakeup, Gathering data...");

        m.content.value = 1;

        msg_send(&m, pid, true);
    }
}
