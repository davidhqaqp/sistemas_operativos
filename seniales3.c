#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int contador = 0;

void mostrarMensaje();
void invocarCowsay();

int main(){

  signal (SIGTERM, mostrarMensaje);
  signal (SIGUSR2, invocarCowsay);

  printf("Bienvenido \n");

  int pid=fork();
  if(pid=0){
    printf("Hijo \n");
    invocarMensaje();
  }else{
    printf("Padre \n");
    mostrarMensaje();
  }
  exit(0);
  return 0;
}
void mostrarMensaje(){
  signal(SIGTERM,SIG_IGN);
  contador++;
  printf("Se dio %d veces\n",contador);
}

void invocarMensaje(){
  signal(SIGUSR2,SIG_IGN);
  exec('cowsay', 'hola');
  printf("Se invoco cowsay");
}
