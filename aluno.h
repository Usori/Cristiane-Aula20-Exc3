#include <stdio.h>
#include <stdlib.h>


typedef struct aluno{
	int ra;
	int ano;
	double nota;

}aluno;

//typedef struct studant aluno;

aluno* cria_aluno(int ra, int ano, double nota){
	aluno* studant = (aluno*) malloc (sizeof(aluno));
	if(studant == NULL){
			fprintf(stderr, "Erro ao tentar criar um aluno");		
			return NULL;
	}

	studant->ra = ra;
	studant->ano = ano;
	studant->nota = nota;

	return studant;
}



aluno** aloca_classe(int numAlunos){
	aluno** classroom = (aluno**) malloc (sizeof(aluno)*numAlunos);
	if(classroom == NULL){
			fprintf(stderr, "Erro ao tentar criar um aluno");		
			return NULL;
	}	
	int i;
	for(i=0;i<numAlunos;i++) classroom[i] = cria_aluno(10000000, 1000, 0);

	return classroom;
}


void imprime_aluno(aluno* a){
	printf("%8d %4d %5.2lf\n", a->ra, a->ano, a->nota);
}

void modifica_aluno(aluno* studant, int ra, int ano, double nota){
	if(studant == NULL) return;

	studant->ra = ra;
	studant->ano = ano;
	studant->nota = nota;

}

void imprime_classe(aluno** classe, int numAlunos){
	int i;
	for(i=0;i<numAlunos;i++){
			imprime_aluno(classe[i]);
	}

}


int comparaNota(const void* x, const void* y){
	double a1 = (*(aluno**)x)->nota;
	double a2 = (*(aluno**)y)->nota;
	if(a1 == a2) return 0; // são iguais
	
	if(a1 < a2) return -1; // vem antes
	else return 1; // vem depois
	
			

}

int comparaAno(const void* x, const void* y){
	int a1 = (*(aluno**)x)->ano;
	int a2 = (*(aluno**)y)->ano;

	if(a1 == a2) return 0; // são iguais
	
	if(a1 < a2) return -1; // vem antes
	else return 1; // vem depois

}

void ordena_nota(aluno** classe, int numAlunos){
	qsort(classe, 4, sizeof(aluno*), comparaNota);
}

void ordena_ano(aluno** classe, int numAlunos){
	qsort(classe, 4, sizeof(aluno*), comparaAno);
}

double media(aluno** classe, int numAlunos){
	int i;	
	double media;
	for(i=0;i<numAlunos;i++){
			media+=classe[i]->nota;
	}

	return media/numAlunos;

}
