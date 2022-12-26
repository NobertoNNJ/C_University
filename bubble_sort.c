#include <stdio.h>

int procurar(int vet[],int tam, int x){
  int ini = 0;
  int fim = tam-1;
  int meio;

  while(ini<=fim){
    meio = (ini+fim)/2;
    if (x==vet[meio]){
       return meio;
  } else if(x<vet[meio]){
      fim = meio-1;
  } else{
    ini = meio+1;
  }
}
return -1;
}

int main(void)
{
int valores[10];
int i,j,x;
int aux;
int res;

for(i=0;i<10;i++){
  printf("Valor na posição %d: ", i);
  scanf("%d", &valores[i]);
}
 for (j=0;j<10;j++){
  for (i=0;i<10;i++){
    if(valores[i]>valores[i+1]){
		aux=valores[i];
		valores[i]=valores[i+1];
		valores[i+1]=aux;
    }
  }
  }
  printf("Valor para procura no vetor:");
  scanf("%d", &x);
  res = procurar(valores,10,x);
  if(res!= -1){
    printf("Valor %d encontrado na posição %d que tem o valor %d",x,res,valores[res]);
  }
  else{
    printf("valor não encontrado");
  }
return(0);
}
