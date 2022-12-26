#include <stdio.h>

void trocar(int *x,int *y);

int main(void) {
  
  int a,b;
  a = 5;
  b= 8;
  printf("valor de a = %d e b = %d antes da função",a,b);
  trocar(&a,&b); 
  printf("\nvalor de a = %d e b = %d depois da função",a,b);
  
}

void trocar(int *x,int *y){
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}
