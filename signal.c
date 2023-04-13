/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int handler_called = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handler_called = 1;
}


int main(int argc, char * argv[]){
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    if(handler_called){
      printf("Turing was right!\n");
      handler_called = 0;
      alarm(1);
    }
  }; //busy wait for signal to be delivered
  return 0; //never reached
}