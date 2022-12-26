#include <stdio.h>
#include <string.h>

int main()
{
  float mult[2][10][2];
	char nomes[20][25];
	int i,j,k;

	for (i=0;i<20;i++){
    printf("nome do aluno:");
    scanf("%s", nomes[i]);
		}
	for (i=0;i<2;i++){
		for (j=0;j<10;j++){
             printf("notas do aluno %d da turma %d:",j+1,i+1);
			for (k=0;k<2;k++){
				scanf("%2f",&mult[i][j][k]);
			}
		}
	}
	for (i=0;i<2;i++){
    	printf("turma %d:", i+1);
      printf("\n");
		for (j=0;j<10;j++){
      if (i==0){
      printf("%s", nomes[j]);
      }
      else{
        printf("%s", nomes[j+10]);
      }
			for (k=0;k<2;k++){
				printf("%.2f, ",mult[i][j][k]);
			}
			printf("\n");
		}
	}
return(0);
