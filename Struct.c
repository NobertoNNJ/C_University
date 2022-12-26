#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
  char nome[50];
  struct aluno *prox;
} Funcionario;

Funcionario* inicializar(){
  return NULL;
}

void inserir_fim(Funcionario** lista, char nome[50]){
  Funcionario* novo = malloc(sizeof(Funcionario));
  strcpy(novo->nome,nome);
  if(*lista==NULL){
    *lista = novo;
    (*lista)->prox = NULL;
  } else {
    Funcionario* p = *lista;
    while(p->prox!=NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
}

void imprimir(Funcionario* lista){
  printf("lista completa de contribuintes:\n");
  while(lista != NULL){
    printf("%s\n",lista->nome);
    lista=lista->prox;
  }
}

void remover_inicio(Funcionario** lista){
  if(*lista != NULL){
    Funcionario* aux = *lista;
    *lista = (*lista)->prox;
    free(aux);
  }
}

int main(void) {
  int i,j=0,k=0;
  char pessoa[50];

  Funcionario* lista = inicializar();
  while(j != 2){
    printf("Adicionar contribuinte? se sim digite 1, se não digite 2.");
    scanf("%d", &j);
    if(j==1){
    printf("Nome do novo contribuinte:\n");
    scanf("%s",pessoa);
    inserir_fim(&lista, pessoa);
    }
    printf("estão precisando de café? se sim digite 1, se não digite 2.");
    scanf("%d", &k);
    if(k==1){
      printf("proximo a comprar: %s\n",lista->nome);
      inserir_fim(&lista, lista->nome);
      remover_inicio(&lista);
    }
    if(j!=1 && k !=1){
      return 0;
    }
  }
  imprimir(lista);
  inserir_fim(&lista, lista->nome);
  remover_inicio(&lista);
  printf("----------------\n");
  imprimir(lista);
  return 0;
}
