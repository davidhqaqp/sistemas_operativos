#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void mostrar();
void ejecutar();

int main(){

  signal (SIGTERM, mostrarMensaje);
  signal (SIGUSR2, invocarCowsay);

  printf("Bienvenido \n");

  int pid=fork();
  if(pid=0){
    printf("Hijo1 %d \n",getpid());
    int pid2=fork();
    if(pid=0){
      printf("Hijo2 %d \n",getpid());
      waitpid(1);
    }else{
      exit(0);
    }
  }else{
    printf("Padre \n");
  }
  exit(0);
  return 0;
}
void mostrar(){
  signal(SIGTERM,SIG_IGN);
}

void ejecutar(){
  signal(SIGUSR2,SIG_IGN);
  exec('script.sh');
}
