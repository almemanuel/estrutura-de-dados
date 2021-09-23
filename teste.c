/*
Emanuel de Almeida Souza
2317915
emanuel.1998@alunos.utfpr.edu.br
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct carga{
	int cod;
	float peso;
	struct carga *prox;
}Carga;

typedef Carga *Conteiner;

Conteiner *cria_conteiner();
void insere_carga(Conteiner *conteiner, int cod);
void imprime_conteiner (Conteiner *conteiner);
void carrega_conteiner(Conteiner *conteiner, float pesomax);
int sem_cargas(Conteiner *eletronicos, Conteiner *vestuario, Conteiner *geral);


int main() {
	Conteiner *eletronicos = cria_conteiner();
	Conteiner *vestuario = cria_conteiner();
	Conteiner *geral = cria_conteiner();
	char tipo;
    int contelet = 0, contvest = 0, contger = 0;

	int op = 0;
	while(op!=5) {
		printf("\n1 - Inserir Carga");
		printf("\n2 - Consultar Conteiner");
		printf("\n3 - Carregar Conteiner");
		printf("\n4 - Otimizar Conteiner");
		printf("\n5 - Sair");
		printf("\nInforme opcao:");
		scanf("%d",&op);

		switch(op) {
			case 1: {
				do {
        			setbuf(stdin, NULL);
					printf("\nTIPOS DE CARGA:\n\tE - Eletronicos\n\tV - Vestuario\n\tG - Geral\nSelecione um tipo: ");
					scanf("%c", &tipo);
					setbuf(stdin, NULL);
					tipo = toupper(tipo);
				} while(!strcmp(&tipo, "E") && !strcmp(&tipo, "V") && !strcmp(&tipo, "V"));

				if(strcmp(&tipo, "E")) {
                    contelet += 1;
                    insere_carga(eletronicos, contelet);
                } else if(strcmp(&tipo, "V")) {
                    contvest += 1;
                    insere_carga(vestuario, contvest);
                } else {
                    contger += 1;
                    insere_carga(geral, contger);
                }

			} break;

			case 2: {
				do {
        			setbuf(stdin, NULL);
					printf("\nTIPOS DE CARGA:\n\tE - Eletronicos\n\tV - Vestuario\n\tG - Geral\nSelecione um tipo: ");
					scanf("%c", &tipo);
					setbuf(stdin, NULL);
					tipo = toupper(tipo);
				} while(!strcmp(&tipo, "E") && !strcmp(&tipo, "V") && !strcmp(&tipo, "V"));

				if(strcmp(&tipo, "E")) imprime_conteiner(eletronicos);
				else if(strcmp(&tipo, "V")) imprime_conteiner(vestuario);
				else imprime_conteiner(geral);

			} break;

			case 3: {
                if(sem_cargas(eletronicos, vestuario, geral)) printf("\nSem carga disponivel");
        		do {
                    setbuf(stdin, NULL);
                    printf("\nTIPOS DE CARGA:\n\tE - Eletronicos\n\tV - Vestuario\n\tG - Geral\nSelecione um tipo: ");
                    scanf("%c", &tipo);
                    tipo = toupper(tipo);
                } while(!strcmp(&tipo, "E") && !strcmp(&tipo, "V") && !strcmp(&tipo, "V"));

                float pesomax;
                do {
                    setbuf(stdin, NULL);
                    printf("\nInforme peso maximo (em toneladas) do conteiner a ser carregado: ");
                    scanf("%f", &pesomax);
                } while(pesomax < 0);

                if(strcmp(&tipo, "E")) carrega_conteiner(eletronicos, pesomax);
				else if(strcmp(&tipo, "V")) carrega_conteiner(vestuario, pesomax);
				else carrega_conteiner(geral, pesomax);

			} break;

			case 4: {

			} break;
		}
	}
}


Conteiner *cria_conteiner() {
    Conteiner *conteiner = (Conteiner *) malloc(sizeof(Conteiner));
    if(conteiner != NULL) *conteiner = NULL;
    return conteiner;
}


void insere_carga(Conteiner *conteiner, int cod) {
    if(conteiner == NULL) return;
    Carga *aux = (Carga *) malloc(sizeof(Carga));
    if(aux == NULL) return;

	float peso;
    aux->cod = cod;
	do {
		printf("\nInforme o peso do conteiner %i em toneladas: ", aux->cod);
        scanf("%f", &peso);
	} while(peso < 0);
	aux->peso = peso;
    aux->prox = *conteiner;
    *conteiner = aux;
}


void imprime_conteiner (Conteiner *conteiner) {
	if(conteiner == NULL) return;
	printf("\nAguardando carregamento:\n\t");
	Carga *aux = *conteiner;
	while(aux != NULL) {
		printf("%i ", aux->cod);
		aux = aux->prox;
	}
}


void carrega_conteiner(Conteiner *conteiner, float pesomax) {
    if(conteiner == NULL || *conteiner == NULL) {
        printf("\nNao ha cargas deste tipo. Volte e selecione outra opcao");
        return;
    }
    Carga *ant, *aux = *conteiner;

    if(aux->peso > pesomax && aux != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL) return;
    if(aux == *conteiner) *conteiner = aux->prox;
    else ant->prox = aux->prox;
    free(aux);
    aux = NULL;
    return;
}


int sem_cargas(Conteiner *eletronicos, Conteiner *vestuario, Conteiner *geral) {
    if(*eletronicos == NULL && *vestuario == NULL && *geral == NULL) return 1;
    return 0;
}