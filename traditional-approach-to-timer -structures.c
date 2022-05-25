#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void timer_callback(int signum)
{
    time_t now = time(NULL);
    printf("Signal %d caught on %li\n", signum, now);
}

int main()
{
    signal(SIGALRM, timer_callback);
    alarm(1);
    sleep(3);
    return 0;
}