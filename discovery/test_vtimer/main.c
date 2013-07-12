#include <stdio.h>
#include <hwtimer.h>
#include <timex.h>
#include <vtimer.h>

int main(void)
{
    timex_t now;

    hwtimer_init();
    vtimer_init();

    while (1) {
        vtimer_now(&now);
        timex_print(now);
        vtimer_usleep(1000000);
    }
}
