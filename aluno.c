#include "aluno.h"

void main(){

  aluno *a1;
  aluno **classe;
  int i;

  a1 = cria_aluno(123456, 2014, 9);
  imprime_aluno(a1);

  classe = aloca_classe(4);
  modifica_aluno(classe[0],11111111, 2014, 4.5);
  modifica_aluno(classe[1],22222222, 2016, 7.5);
  modifica_aluno(classe[2],33333333, 2010, 9);
  modifica_aluno(classe[3],44444444, 2009, 8);
  
	printf("Sem Ordenar:\n"); /* Demonstração da função imprime_classe() */
	imprime_classe(classe,4); /* Não foi pedido no exercício, isso é um extra */

  printf("Por nota:\n");
  ordena_nota(classe,4);
  for(i=0;i<4;i++) imprime_aluno(classe[i]);
  
  printf("Por ano:\n");
  ordena_ano(classe,4);
  for(i=0;i<4;i++) imprime_aluno(classe[i]);
  
	printf("Media %.2lf\n", media(classe,4));


}
