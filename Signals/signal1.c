#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int isr_executed = 0;

void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
        printf("KK pressed Ctrl-C . . . \n");
        isr_executed = 1;
    }
}

int main(void)
{
    signal(SIGINT, sig_handler);
    printf("Waiting for signal . . .\n");
    while(!isr_executed);
}
