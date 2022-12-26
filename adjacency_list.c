#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int vertices, tipo;
  char grafo[vertices][100];
  int i, j, v;

  printf("quantos vertices tem o grafo?");
  scanf("%d", &vertices);

for(i = 0; i< vertices; i++){
 for(j = 0; j < vertices; j++){
     printf("\nO vertice %d esta ligado ao vertice %d? digite 1 para sim e 2 para não!",i,j);
     scanf("%d", &v);
     if (v == 1){
       printf("\nQuantas ligações?");
       scanf("%d", &v);
       grafo[i][100] = "->[j;v]";
     }
     
 }
}
for(i = 0; i< vertices; i++){
  printf("%s", grafo[i]);
}
  return 0;
}
