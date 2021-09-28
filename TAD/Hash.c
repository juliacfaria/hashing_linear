#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#define TAMPESO 50

void inicializa(Hash* hash, int M){
  (*hash).vetor = (Item*)malloc(M*sizeof(Item));
  (*hash).M = M;


  // inicialização com valores pré-definidos é necessária
  int i;
  for(i=0;i<M;i++){
   (*hash).vetor[i].codigo = -1;
   (*hash).vetor[i].nome = ""; // atribuição com "=" é possível pois foi definido como ponteiro
  }
}

void geraPesosHashingUniversal(int *pesos){
  int i;

  printf("Vetor de pesos: ");
  for(i=0;i<TAMPESO;i++){
    pesos[i] = rand() % TAMPESO;
    printf("%d ", pesos[i]);
  }
  printf("\n");
}


int hashingUniversal(char *nome, int M, int *pesos){
  int n = strlen(nome);
  int i, resultado = 0;
  for(i=0;i<n;i++){
    resultado += (int)(nome[i]) * pesos[i];
  }

  return resultado%M; // já retornando a posição onde inserir
}

void insere(Hash* hash, char* nome, int codigo, int *pesos){
  int M = (*hash).M;
  int indice = hashingUniversal(nome, M, pesos);

  if((*hash).vetor[indice].codigo == -1){
    (*hash).vetor[indice].codigo = codigo;
    (*hash).vetor[indice].nome = nome;
    printf("Indice que inseriu: %d\n", indice);
  }else{
    int qtd = 1;
    while(qtd < M){
      printf("Anda um, era pra ser %d\n", indice);
      indice = (indice+1)%M;
      if((*hash).vetor[indice].codigo == -1){
        (*hash).vetor[indice].codigo = codigo;
        (*hash).vetor[indice].nome = nome;
        printf("Indice que inseriu: %d\n", indice);
        break;
      }
      qtd++;
    }
    if(qtd == M){
      printf("TABELA CHEIA!!\n");
    }
  }
}

void printaDadosInseridos(Hash* hash){
  int i, tamanho =(*hash).M;
  printf("\n\nDados\n");
  for(i=0;i<tamanho;i++){
    printf("Cod: %d Nome: %s\n", hash->vetor[i].codigo, hash->vetor[i].nome);
  }
}

void pesquisa(Hash* hash, char* nome, int *pesos){
  int M = (*hash).M;
  int indice = hashingUniversal(nome, M, pesos);
  
  printf("Indice calculado: %d\n", indice);
  int passadasExtras = 0;

  while(passadasExtras<M){
    if((*hash).vetor[indice].nome == nome){
      printf("Encontrado!! Indice: %d Nome: %s Codigo: %d\n", indice, (*hash).vetor[indice].nome, (*hash).vetor[indice].codigo);
      break;
    }
    passadasExtras++;
    indice = (indice+1)%M;
  }

  if(passadasExtras == M)
    printf("%s não encontrado\n\n", nome);
  else
    printf("Passadas extras(caso nao tenha encontrado de primeira): %d\n\n", passadasExtras);
}
