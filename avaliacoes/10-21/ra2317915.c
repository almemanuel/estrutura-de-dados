/************************************/
/* Emanuel de Almeida Souza         */
/* 2317915                          */
/* emanuel.1998@alunos.utfpr.edu.br */
/************************************/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct cliente {
    char nome_cli[20], telefone[15], procedimento[10];
    float valor_procedimento;
} Tcliente;

typedef struct atendimentos {
    int dia;
    int qtde; //quantidade de clientes atendidos no dia
    Tcliente *cliente; //dados dos clientes
} Tagenda;


Tagenda *aloca_agenda(Tagenda *agenda, int dia);
void aloca_atendimentos(Tagenda *agenda);
void armazena_cliente(Tagenda *agenda);
void imprime_cliente(Tagenda *agenda, int dia);
void desaloca_atendimentos(Tagenda *agenda, int dia);

int main() {
	//defini��es de variaveis
	int tam, op=0;
	printf("Informe numero de dias da agenda:");
	scanf("%d",&tam);
    Tagenda *agenda = NULL;
	while(op!=6) {
		printf("\n1 - Alocar agenda");
		printf("\n2 - Alocar atendimentos");
		printf("\n3 - Armazenar cliente");
		printf("\n4 - Imprimir clientes");
		printf("\n5 - Desalocar agenda/atendimentos");
		printf("\n6 - Sair");
		printf("\nInforme opcao:");
		scanf("%d",&op);
		switch(op) {
			case 1:
			{
                agenda = aloca_agenda(agenda, tam);
			} break;

			case 2:
			{
                aloca_atendimentos(agenda);
			} break;

			case 3:
			{
                armazena_cliente(agenda);
			} break;

			case 4:
			{
                do {
                    printf("Informe o dia que deseja visualizar: ");
                    scanf("%i", &dia);
                } while(dia < 1);
                imprime_cliente(agenda, dia);
			} break;

            case 5:
			{
                do {
                    printf("Informe o dia que deseja cancelar: ");
                    scanf("%i", &dia);
                } while(dia < 1);
                desaloca_atendimentos(agenda, dia);
			} break;

			case 6:
			{
                printf("FIM\n");
                return 0;
			} break;
		}
	}

    return 0;
}


Tagenda *aloca_agenda(Tagenda *agenda, int dia) {
    agenda = malloc(sizeof(Tagenda) * dia);
    for(int i = 0; i < dia; i++) {
        (agenda + i)->dia = i + 1;
    }
    return agenda;
}


void aloca_atendimentos(Tagenda *agenda) {
    if(agenda == NULL) {
        printf("ERRO");
        return;
    }
    for(int i = 0; (agenda + i)->dia != 0; i++) {
        do {
            printf("Quantidade de atendimentos no dia %i: ", (agenda + i)->dia);
            scanf("%i", &(agenda + i)->qtde);
        } while((agenda + i)->qtde < 0);
        (agenda + i)->cliente = malloc(sizeof(Tcliente) * (agenda + i)->qtde);
    }
}


void armazena_cliente(Tagenda *agenda) {
    if(agenda == NULL) {
        printf("ERRO");
        return;
    }
    for(int i = 0; (agenda + i)->dia != 0; i++) {
        printf("DIA %i\n", (agenda + i)->dia);
        for(int j = 0; j < (agenda + i)->qtde; j++) {
            while(1 == 1) {
                printf("\tATENDIMENTO %i\n", j);
                setbuf(stdin, NULL);
                printf("\t\tNome: ");
                fgets((agenda + i)->cliente[j].nome_cli, 20, stdin);
                setbuf(stdin, NULL);
                printf("\t\tTelefone: ");
                fgets((agenda + i)->cliente[j].telefone, 15, stdin);
                setbuf(stdin, NULL);
                printf("\t\tProcedimento: ");
                fgets((agenda + i)->cliente[j].procedimento, 10, stdin);
                setbuf(stdin, NULL);
                int k;
                for(k = 0; k < j; k++) {
                    if(!(strcasecmp((agenda + i)->cliente[j].nome_cli, (agenda + i)->cliente[k].nome_cli)) && !(strcasecmp((agenda + i)->cliente[j].telefone, (agenda + i)->cliente[k].telefone)) && !(strcasecmp((agenda + i)->cliente[j].procedimento, (agenda + i)->cliente[k].procedimento))) break;
                }
                if(k < j) {
                    printf("\tCliente e procedimento ja cadastrados\n");
                } else {
                    do {
                        printf("Preco: ");
                        scanf("%f", (agenda + i)->cliente[j].valor_procedimento);
                    } while((agenda + i)->cliente[j].valor_procedimento) <= 0);
                    break;
                }
            }
        }
    }
}


void imprime_cliente(Tagenda *agenda, int dia) {
    int i;
    for(i = 0; (agenda + i)->dia == dia || (agenda + i)->dia == 0; i++) {
        if((agenda + i)->dia == 0) {
            printf("Dia inexistente\n");
            return;
        }
    }
    for(int j = 0; j < (agenda + i)->qtde; j++) {
        printf("%i\n%s%s%s", j + 1, (agenda + i)->cliente[j].nome_cli, (agenda + i)->cliente[j].telefone, (agenda + i)->cliente[j].procedimento);
    }
}


void desaloca_atendimentos(Tagenda *agenda, int dia) {
    int i;
    for(i = 0; (agenda + i)->dia == dia || (agenda + i)->dia == 0; i++) {
        if((agenda + i)->dia == 0) {
            printf("Dia inexistente\n");
            return;
        }
    }
    for(int j = (agenda + i)->qtde; j != 0; j--) {
        free((agenda + i)->cliente[j]);
        *(agenda + i)->cliente[j] = NULL;
        (agenda + i)->qtde--;
    }
}