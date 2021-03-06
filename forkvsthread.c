#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void test_fork(void);
void test_thread(void);

static int count;

int main(int argc, char *argv[]) 
{
    int modo;
    
    // Chequea número de argumentos
    if (argc < 3) {
        fprintf(stderr, "Uso: %s modo contador\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Obtiene los argumentos
    modo = atoi(argv[1]);
    count = atoi(argv[2]);
    
    if (count <= 0) {
        fprintf(stderr, "%s: contador debe ser mayor que cero.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (modo != 1 && modo != 2) {
        fprintf(stderr, "%s: modo invalido - usar 1 (fork) o 2 (threads)\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if (modo == 1) {
        printf("Probando fork()...\n");
        test_fork();
    } else if (modo == 2) {
        printf("Probando pthread_create()...\n");
        test_thread();
    }

    exit(EXIT_SUCCESS);
}

//==========================================================================
// Código para la prueba con fork()
//==========================================================================
void funcion_fork() 
{
    int i;
    i = 0;
    i++;
}

void test_fork()
{
    pid_t pid;
    int j, status;

    for (j = 0; j < count; j++) {
        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(0);
        }        
        else if (pid == 0) {
            /* Hijo */
            funcion_fork();
            exit(EXIT_SUCCESS);
        }        
        else {
            /* Padre - espera por el hijo */
            waitpid(pid, &status, 0);
        }
    }
}

//==========================================================================
// Código para la prueba con pthread_create()
//==========================================================================

void *funcion_hilo(void *null) 
{
    int i;
    i = 0;
    i++;
    pthread_exit(NULL);
}

void test_thread() 
{
    int rc, j;
    pthread_t tid;
    
    for (j = 0; j < count; j++) {
        // COMPLETAR
        rc = pthread_create();
        
        if (rc) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
        
        // Espera por el hilo        
        // COMPLETAR
        rc = pthread_join();

        if (rc) {            
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
    
    // COMPLETAR
    pthread_exit();
}
