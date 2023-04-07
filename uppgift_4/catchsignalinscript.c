#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int X = 0;

void increment(int sig) {
    if (sig == SIGINT) {
        syslog(LOG_NOTICE, "Caught SIGINT...");
        X += 500;
        if (X > 2000) {
        syslog(LOG_ALERT, "Okay, I'll quit...");
        exit(1);
        } else {
        syslog(LOG_WARNING, "Don't you provoke me...");
        }
    }
}

int main() {
    signal(SIGINT, increment);

    while (1) {
        syslog(LOG_INFO, "X=%d", X);
        X++;
        sleep(1);
    }
    return 0;
}
