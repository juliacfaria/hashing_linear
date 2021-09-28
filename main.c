#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TAD/Hash.h"

#define M 5 // tamanho do meu vetor
#define N 15
#define TAMPESO 50

int main(){
  Hash hash;

  srand(time(NULL)); // necessário para gerar o vetor de pesos aleatórios

  int pesos[TAMPESO];

  geraPesosHashingUniversal(pesos);
  
  inicializa(&hash, M);

  insere(&hash, "julia", 123, pesos);
  insere(&hash, "teste", 113, pesos);
  insere(&hash, "nomegrande", 103, pesos);
  insere(&hash, "ana", 183, pesos);
  insere(&hash, "nomemuitograndemesmo", 173, pesos);
  printaDadosInseridos(&hash);
  
  printf("\n\nPESQUISA:\n\n");

  pesquisa(&hash, "naoestanalista", pesos);
  pesquisa(&hash, "nomegrande", pesos);
  pesquisa(&hash, "teste", pesos);
  pesquisa(&hash, "outronome", pesos);

  return 0;
}