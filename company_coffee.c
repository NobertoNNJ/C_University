#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
  char nome[50];
  struct funcionario *prox;
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
  while(lista != NULL){
    printf("Nome: %s\n",lista->nome);
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
  int i, j=0;
  int quant;
  char pessoa[50];
  printf("Quantas pessoas participam do clube do café?\n");
  scanf("%d", &quant);

  Funcionario* lista = inicializar();
  for (i = 0; i < quant;i++){
    printf("Nome do %d contribuinte da lista:\n", i+1);
    scanf("%s",pessoa);
    inserir_fim(&lista, pessoa);
  }
  while(j!=3){
    printf("digite:\n1 para inserir novo contribuinte. \n2 para informar proximo membro a contribuir. \n3 para imprirmir lista completa.\n");
    scanf("%d", &j);
    if(j==1){
      printf("Nome do novo contribuinte.\n");
    scanf("%s",pessoa);
    inserir_fim(&lista, pessoa);
    }
    if(j==2){
       printf("Comprar café: %s\n",lista->nome);
       inserir_fim(&lista, lista->nome);
       remover_inicio(&lista);
    }
    if(j==3){
      printf("lista completa:\n");
      imprimir(lista);
    }
  }
  return 0;
}
