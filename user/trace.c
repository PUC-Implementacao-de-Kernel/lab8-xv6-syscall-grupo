#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int mask;

  if(argc < 3){
    fprintf(2, "uso: trace mask comando [args...]\n");
    exit(1);
  }

  mask = atoi(argv[1]);

  /* TODO 1: chame trace(mask). */
  if(trace(mask) < 0){
    /* se a chamada der erro*/
    fprintf(2, "trace: falha ao configurar mask\n");
    exit(1);
  }

  /* TODO 2: execute o comando recebido em argv[2]. 
   * argv[2] é o nome do programa
   * &argv[2] é o ponteiro para o início do vetor de argumentos do novo programa
   */
  exec(argv[2], &argv[2]);

  fprintf(2, "trace: exec %s falhou\n", argv[2]);
  exit(1);
}