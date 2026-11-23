#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;
  printf("Generando muchas syscalls...\n");
  for (i = 0; i < 50; i++) {
    // Genera actividad
    int fd = open("README", 0);
    if (fd >= 0) close(fd);
  }
  printf("Listo\n");
  exit(0);
}