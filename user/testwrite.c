#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  int i;

  printf("==================================================\n");
  printf(" PRUEBA SENTINEL: DETECCION DE EXCESO DE WRITE\n");
  printf(" Explicacion: Este programa simula un ataque de\n");
  printf(" saturacion de E/S realizando mas de 50 llamadas\n");
  printf(" write() consecutivas para activar el bloqueo.\n");
  printf("==================================================\n\n");

  int fd = open("test_io.txt", O_CREATE | O_WRONLY);
  if (fd < 0) {
    printf("Error al crear archivo de prueba\n");
    exit(1);
  }

  printf("Iniciando rafaga de escrituras...\n");
  for (i = 0; i < 60; i++) {
    write(fd, "Datos de prueba Sentinel\n", 25);
  }

  close(fd);
  printf("Prueba finalizada sin bloqueo.\n");
  exit(0);
}