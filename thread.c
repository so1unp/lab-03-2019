#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>     // exit()
#include <unistd.h>     // sleep()
#include <stdint.h>     // intptr_t

int contador;

void* funcion_hilo(void*);

int main(int argc, char* argv[])
{
    // Identificador del hilo (similar a pid_t)
    pthread_t hilo;

    // Verifica el número de argumentos
    if (argc != 2) {
        fprintf(stderr, "Uso: %s contador\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Número de repeticiones
    contador = atoi(argv[1]);

    int ret = 0;

    // Crea el hilo
    // COMPLETAR
    ret = pthread_create();

    // Chequea por error en la creación del hilo
    if(ret != 0)
    {
        perror("pthread_create");
    }

    // Espera a que el hilo finalice
    // COMPLETAR
    ret = pthread_join();
    
    // Chequea por error al esperar por la finalización del hilo
    if(ret != 0)
    {
        perror("pthread_join");
    }

    printf("El hilo finalizó.\n");

    // Finaliza el proceso
    exit(EXIT_SUCCESS);
}
    
// Esta es la función que ejecuta el hilo
void* funcion_hilo(void* param)
{
    int i;

    // Imprime varias veces hola por la salida estándar
    for(i = 0; i < contador; i++)
    {
        printf("[%d] ¡Hola!\n", i);
        sleep(1);
    }

    // Finaliza el hilo
    // COMPLETAR
    pthread_exit();
}
