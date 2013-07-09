#include <stdio.h>
#include <hwtimer.h>
#include <kernel.h>

void callback(void* ptr) {
    puts((char*)ptr);
}

int main(void)
{
    puts("hwtimer test project.");

    puts("Initializing hwtimer...");
    hwtimer_init();

    puts("Initializing hwtimer [OK].");

    hwtimer_set(5 * HWTIMER_SPEED, callback, (void*)"callback");

    puts("hwtimer set.");

    while (1);
}
