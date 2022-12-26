#include <stdio.h>
#include <string.h>

struct idade{
int p;
};

struct nota{
int m;
};

struct Aluno{
	int matricula;
  struct idade d;
  struct nota n;
	char nome[10];
};

void ler(struct Aluno lista[]){
	
int i;

for (i=0;i<2;i++){
	printf("Insira a matricula e o nome do aluno %d:\n",i+1);
	scanf("%d",&lista[i].matricula);
	fflush(stdin);
	gets(lista[i].nome);
	printf("Insira a idade aluno %d:\n",i+1);
	scanf("%d",&lista[i].d.p);
  printf("Qual a nota do aluno %d:\n",i+1);
  scanf("%d",&lista[i].n.m);
}

for (i=0;i<2;i++){
	printf("A matricula do aluno %s eh %d:\n",lista[i].nome,lista[i].matricula);
	printf("idade: %d\n", lista[i].d.p);
  printf("nota do aluno: %d\n",lista[i].n.m);
	
	
}
	
}


main( )
{
printf("Estruturas (Registros)\n");

struct Aluno lista[2];

ler(lista);


return(0);
}
