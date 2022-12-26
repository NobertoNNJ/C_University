#include <stdio.h>

int fat(int n){
  
if (n==0){
	return 1;
}
return n*fat(n-1);
}
main( )
{
printf("Fatorial\n");

int n;

scanf("%d", &n);

printf("O valor da soma total eh %d", fat(n));

return(0);
}
