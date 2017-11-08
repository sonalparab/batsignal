#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int f = open("msgs",O_CREAT|O_WRONLY,0666);
    char msg[] = "I've been INTerrupted";
    write(f,msg,sizeof(msg));
    close(f);
    exit(0);
  }
  
  if(signo == SIGUSR1){
    printf("Hi I'm the parent: %d\n",getpid());
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("Hi I'm: %d\n",getpid());
    sleep(1);
  }
  return 0;
  
}
