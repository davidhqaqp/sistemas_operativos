#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int ncortes = 0;
int bucle = 1;

void alarma();
void cortar();

int main(){
	signal (SIGINT, cortar);
	signal (SIGALRM,alarma);

	printf("ejemplo de señal \n");
	printf("pulse varias veces CTRL+C  \n");
	alarm(15);
	while(bucle);
	signal (SIGINT, SIG_IGN);
	printf("ha intentado cortar %d \n",ncortes);
	printf("hasta luego  \n");
	exit(0);

	return 0;	
}

void cortar(){
	signal(SIGINT, SIG_IGN);
	printf("has pulsado control  \n");
	ncortes++;
	signal(SIGINT,cortar);
	
}

void alarma(){
	signal(SIGALRM, SIG_IGN);
	bucle=0;
	printf("Alarma\n");
}

