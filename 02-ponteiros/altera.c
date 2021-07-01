/**************************************************************************
Altere o programa 1, alterando o valor das variáveis através dos ponteiros.
void main() {
    int a = 32 ;
    float b = 10.6 ;
    char c = ‘w’ ;
    int *pa = &a ;
    float *pb = &b ;
    char *pc = &c ;
    .....
}
**************************************************************************/

#include<stdio.h>

int main() {
    int a = 32;
    float b = 10.6;
    char c = 'w';
    int *pa = &a;
    float *pb = &b;
    char *pc = &c;

    printf("Digite um valor pertencente ao conjunto dos numeros inteiros: ");
    scanf("%i", pa);
    printf("Digite um valor pertencente ao conjunto dos numeros racionais: ");
    scanf("%f", pb);
    setbuf(stdin, NULL);
    printf("Digite um caracter qualquer: ");
    fgets(pc, 2, stdin);

    printf("TAMANHO DAS VARIAVEIS\na = %lu bytes\nb = %lu  bytes\nc = %lu  bytes", sizeof(*pa), sizeof(*pb), sizeof(*pc));
    printf("\nCONTEUDO\na = %i\nb = %.1f\nc = %c", *pa, *pb, *pc);
    printf("\nENDERECO\na = %p\nb = %p\nc = %p", pa, pb, pc);

    return 0;
}
