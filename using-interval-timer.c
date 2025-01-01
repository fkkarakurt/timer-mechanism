#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>
#include "./debug.h"

void timer_callback(int signum)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    printf("Signal %d caught on %li.%03li\n", signum, now.tv_sec, now.tv_usec / 1000);
}

void setup_timer()
{
    struct itimerval new_timer;

    new_timer.it_value.tv_sec = 1;
    new_timer.it_value.tv_usec = 0;
    new_timer.it_interval.tv_sec = 0;
    new_timer.it_interval.tv_usec = 300 * 1000;

    if (setitimer(ITIMER_REAL, &new_timer, NULL) == -1)
    {
        errorf("Failed to set timer: %s", strerror(errno));
    }
    else
    {
        infof("Timer successfully set");
    }
}

int main()
{
    unsigned int remaining = 3;

    signal(SIGALRM, timer_callback);
    setup_timer();

    while (sleep(remaining) != 0)
    {
        if (errno == EINTR)
        {
            debugf("sleep interrupted by signal");
        }
        else
        {
            errorf("sleep error: %s", strerror(errno));
        }
    }

    return 0;
}