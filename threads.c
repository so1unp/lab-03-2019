#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>       // sin(), tan()
#include <unistd.h>     // sleep()
#include <string.h>     // strerror()

// Esta función realiza varios cientos de miles veces una
// multiplicación para consumir CPU.
void* hilo(void *t)
{
    int i;
    double result = 0.0;

    sleep(3);

    for(i = 0; i < 100000; i++) 
    {
        result = result + sin(i) * tan(i);
    }

    printf("[%ld] ¡Hola!\n", (long) t);

    // COMPLETAR
    pthread_exit();
}

int main(int argc, char *argv[])
{
    pthread_t *threads;
    int rc; 
    long t;

    // Comprueba el número de argumentos
    if (argc != 2) {
        fprintf(stderr, "Uso: %s hilos\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Número de hilos a crear
    int n = atoi(argv[1]);

    // Arreglo de identificadores de hilos
    threads = (pthread_t*) malloc(n * sizeof(pthread_t));

    for(t = 0; t < n; t++) {
        // Crea el hilo, y le pasa t como parametro
        // COMPLETAR
        rc = pthread_create();

        if (rc) {
            perror("pthread_create");
        }

        // No nos interesa realizar luego un join con el hilo
        // COMPLETAR
        pthread_detach();
    }

    // Indica el número de hilos creados
    printf("Creados %ld hilos.\n", t);

    // Finaliza el hilo main()
    // COMPLETAR
    pthread_exit();
}
