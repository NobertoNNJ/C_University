#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
  char nome[40];
  char telefone[15];
  char celular[15];
  char email[40];
  struct agenda *prox;
} Agenda;

Agenda* inicializar(){
  return NULL;
}

void exibirMenu(){
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Inserir contato\n"
           "\t02 - Listar contatos\n"
           "\t03 - Buscar contato\n"
           "\t04 - Excluir contato\n"
           "\t05 - Excluir agenda\n"
           "\t06 - Sair\n\n");
}

void inserir_contato(Agenda** lista, char nome[40], char tel[15],char cel[15], char e[40]){
  Agenda* novo = malloc(sizeof(Agenda));
  strcpy(novo->nome,nome);
  strcpy(novo->telefone,tel);
  strcpy(novo->celular,cel);
  strcpy(novo->email,e);
  if(*lista==NULL){
    *lista = novo;
    (*lista)->prox = NULL;
  } else {
    Agenda* p = *lista;
    while(p->prox!=NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
}
void imprimir(Agenda* lista){
  printf("Agenda Telefonica\n");
  while(lista != NULL){
    printf("\nContato\n");
    printf("Nome: %s\n",lista->nome);
    printf("Telefone: %s\n",lista->telefone);
    printf("Celular: %s\n",lista->celular);
    printf("Email: %s\n",lista->email);
    lista=lista->prox;
  }
}
void le_string(char *s, int tamanho)
{
  scanf("%s",s);

    int n = strlen(s);
    if (s[n-1] == '\n') s[n-1] = '\0';
    else
        while (getchar() != '\n');
}
void Buscar_contato(Agenda* lista){
  char cont[40];
  printf("Contato procurado:\n");
  le_string(cont, 40);
  while(lista != NULL){
    if(strcmp(lista->nome,cont)==0){
      printf("Nome: %s\n",lista->nome);
      printf("Telefone: %s\n",lista->telefone);
      printf("Celular: %s\n",lista->celular);
      printf("Email: %s\n",lista->email);
      return;
    }
    else{
      lista = lista->prox;
    }
   printf("Contato não encontrado"); 
  }
}
void excluir_contato(Agenda** lista){
  char cont[40];
  printf("Qual contato deseja escluir?\n");
 le_string(cont, 40);
  while(*lista != NULL){
    if(strcmp((*lista)->nome,cont)==0){
      Agenda* aux = *lista;
     *lista = (*lista)->prox;
     free(aux);
     printf("Contato excluido.");
     return;
    }
    else{
      lista = &(*lista)->prox;
    }
  }
  printf("Contato não encontrado");
}
void excluir_agenda(Agenda** lista){
  while(*lista != NULL){
     Agenda* aux = *lista;
     *lista = (*lista)->prox;
     free(aux);
    }
}

int main(void) {
  int i;
  char name[40],te[15],ce[15],mail[40];
  FILE *agenda;
  agenda = fopen("agenda.txt","w");

  Agenda* lista = inicializar();

  while(i!=6){
    exibirMenu();
    scanf("%d",&i);

    if(i == 1){
      printf("Qual o nome? \n");
      scanf("%s", name);
      printf("Qual o telefone?\n");
      scanf("%s",te);
      printf("Qual o celular?\n");
      scanf("%s",ce);
      printf("Qual o email?\n");
      scanf("%s",mail);
      inserir_contato(&lista, name, te, ce, mail);
    }
    else if(i == 2){
      imprimir(lista);
    }
    else if(i == 3){
      Buscar_contato(lista);
    }
    else if(i == 4){
      excluir_contato(&lista);
    }
    else if(i == 5){
      excluir_agenda(&lista);
    }
    else if(i !=6 ){
      printf("Valor invalido\n");
    }
  }

  fprintf(agenda,"Agenda Telefonica\n");
  while(lista != NULL){
    fprintf(agenda,"\nContato\n");
    fprintf(agenda,"Nome: %s\n",lista->nome);
    fprintf(agenda,"Telefone: %s\n",lista->telefone);
    fprintf(agenda,"Celular: %s\n",lista->celular);
    fprintf(agenda,"Email: %s\n",lista->email);
    lista=lista->prox;
  }
  fclose(agenda);
 
  return 0;
}
