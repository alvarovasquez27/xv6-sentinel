#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int i;
  int pid;

  printf("================================\n");
  printf("   PRUEBA DE DETECCION FORK\n");
  printf("================================\n");
  printf("Generando llamadas fork controladas...\n");

  for (i = 0; i < 11; i++) {
    pid = fork();

    if (pid < 0) {
      printf("Error al crear proceso\n");
      break;
    }

    if (pid == 0) {
      printf("Proceso hijo creado: PID %d\n", getpid());
      exit(0);
    }

    wait(0);
  }

  printf("Prueba fork finalizada\n");
  exit(0);
}
