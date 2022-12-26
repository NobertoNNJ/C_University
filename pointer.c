#include <stdio.h>

int main(void) {
int x = 2,y = 8;
int *p,*q;

p = &x;
q = &y;

printf("o endereço de x é: %p\n", &x);
printf("o valor de x é: %d\n", x);
printf("o valor de p é: %p\n", p);
printf("o valor de *p é: %d\n", *p);
printf("o endereço de y é: %p\n", &y);
printf("o valor de y é: %d\n", y);
printf("o valor de q é: %p\n", q);
printf("o valor de *q é: %d\n", *q);
printf("o endereço de p é: %p\n", &p);
printf("o endereço de q é: %p\n", &q);


 
  return 0;
}
