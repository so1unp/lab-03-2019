#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>

// Esta función realiza varios cientos de miles veces una
// multiplicación para consumir CPU.
void busywork(void)
{
    int i;
    double result = 0.0;

    sleep(3);

    for(i = 0; i < 100000; i++) 
    {
        result = result + sin(i) * tan(i);
    }

    printf("[%d] ¡Hola!\n", getpid());
}

int main(int argc, char* argv[])
{ 
    pid_t pid;
    int n, i;

    // Verifica argumentos
    if (argc != 2) {
        fprintf(stderr, "Uso: %s procesos\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);

    // Creacion de procesos hijos
    for (i=0; i < n; i++) {
        pid = fork();
        if (pid == 0) {
            busywork();
            break;
        } else if (pid < 0) {
            perror("fork");
        }
    }

    // Si es el padre, espera por los hijos
    if (pid > 0) {
        while(wait(NULL) > 0)
            ;
        printf("Todos los procesos hijos terminaron.\n");
    }

    exit(EXIT_SUCCESS);
}
