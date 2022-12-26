#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
void quick_sort(int *a, int esquerda, int direita);
void imprimir_vetor(int *vet, int i, int j);
int PesquisaBinaria (int vet[], int x, int tam);

int main(){
 int i, vet[MAX], valor;
 
 for(i = 0; i < MAX; i++){
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 quick_sort(vet, 0, MAX - 1);
 
 printf("Valores ordenados:");
 
 imprimir_vetor(vet, 0, MAX - 1);
 
 printf("\nValor para procurar");
 scanf("%d", &valor);
 PesquisaBinaria (vet, valor, MAX);

 return 0;
}
 
void quick_sort(int *a, int esquerda, int direita) {
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < direita) {
            i++;
        }
        while(a[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort(a, esquerda, j);
    }
    if(i < direita) {
        quick_sort(a, i, direita);
    }
}
void imprimir_vetor(int *vet, int i, int j){

if (i <= j){
     printf("%d ", vet[i]);
 }
 if (i <= j){
   imprimir_vetor(vet,i+1,j);
 }
}
int PesquisaBinaria (int vet[], int x, int tam){
     int inf = 0;    
     int sup = tam-1;
     int meio;
     
     while (inf <= sup) {
          meio = (inf + sup)/2;
          
          if (x == vet[meio]){
              printf("valor %d encontrado na posição %d", x, meio);
               return 1;
			   }
		  else if (x < vet[meio]){
               sup = meio-1;
           }
          else{
               inf = meio+1;
           }
     }
     if(x != vet[meio]){
      printf("valor %d não encontrado.", x);
      return 0;
     }
}
