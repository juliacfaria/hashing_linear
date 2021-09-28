// struct do item que será armazenado na tabela Hash
typedef struct{
  char *nome; // chave é string para utilizar o Hashing Universal
  int codigo;
}Item;

typedef struct{
  Item *vetor;
  int M; // onde M é o tamanho do vetor
}Hash;

void inicializa(Hash* hash, int M);

void geraPesosHashingUniversal(int *pesos); // deve ser chamada uma vez no início do código da main.c

int hashingUniversal(char *nome, int M, int *pesos);

void insere(Hash* hash, char* nome, int codigo, int *pesos);

void printaDadosInseridos(Hash* hash);

void pesquisa(Hash* hash, char* nome, int *pesos);


