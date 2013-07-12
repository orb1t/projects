#include <stdio.h>
#include <thread.h>
#include <hwtimer.h>
#include <vtimer.h>

int main(void)
{
    unsigned long time = 5000000;

    puts("Initializing timer...");

    hwtimer_init();
    vtimer_init();

    puts("Initializing timer [OK].");

    printf("Sleep for %ld\n", time);

    vtimer_usleep(time);

    puts("Wakeup");

    puts("Sleep forever");

    thread_sleep();

    puts("Should not be here");
}
