#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Exemplo escrita de caractere
int main() {
    FILE *f = fopen("arquivo.txt", "w");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char txt[20] = "My program at C";
    int i;

    for(i = 0; i < strlen(txt); i++)
        fputc(txt[i], f);
        fputc('*', f);
    fclose(f);

    return 0;
} */

/* Exemplo leitura de caractere
int main() {
    FILE *f = fopen("arquivo.txt", "r");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char c;
    int i;
    for(i = 1; c <= 10; i++) {
        c = fgetc(f);
        printf("%c", c);
    }
    char d = fgetc(f);
    while(d != EOF) {
        printf("%c", d);
        d = fgetc(f);
    }
    fclose(f);
    return 0;
}*/

/* Exemplo 1
int main() {
    FILE *f1 = fopen("exemplo1.txt", "r"), *f2 = fopen("resposta1.txt", "w");
    if(f1 == NULL || f2 == NULL) {
        printf("ERRO");
        exit(1);
    }

    char c = fgetc(f1);
    while(c != EOF) {
        fputc(toupper(c), f2);
        c = fgetc(f1);
    }

    fclose(f1);
    fclose(f2);

    return 0;
} */

/* utilizando feof() para verificar se chegou ao fim do arquivo
int main() {
    FILE *f = fopen("arquivo.txt", "r");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char c = fgetc(f);
    while(!feof(f)) {
        printf("%c", c);
        c = fgetc(f);
    }
    fclose(f);
    return 0;
}*/

/* gravando uma string
int main() {
    FILE *f = fopen("arquivo.txt", "w");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char txt[20] = "My program in C";
    if(fputs(txt, f) == EOF) printf("ERRO NA GRAVACAO");
    fclose(f);
    return 0;
} */

/* leitura de string
int main() {
    char str[20];
    FILE *arq = fopen("arquivo.txt", "r");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char *result = fgets(str, 12, arq);
    if(result == NULL) {
        printf("erro na leitura");
    } else {
        printf("%s", str);
    }
    fclose(arq);
    return 0;
} */

/* gravando bin
int main() {
    FILE *arq = fopen("arquivo.txt", "wb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    int total_gravado, v[5];
    int i;
    for(i = 0; i < 5; i++) {
        v[i] = i + 1;
    }
    total_gravado = fwrite(v, sizeof(int), 5, arq);
    if(total_gravado != 5) {
        printf("erro na escrita");
        exit(1);
    }
    fclose(arq);
    return 0;
} */

/* gravando diferentes tipos de dados em um bin
int main() {
    FILE *arq = fopen("dados.txt", "wb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }

    char str[20] = "Hello World!";
    float x = 5;
    int v[5];
    int i;
    for(i = 0; i < 5; i++) {
        v[i] = i + 1;
    }

    fwrite(str, sizeof(char), 20, arq);
    fwrite(&x, sizeof(float), 1, arq);
    fwrite(v, sizeof(int), 5, arq);
    fclose(arq);

    return 0;
}*/

/* gravando struct em bin
int main() {
    typedef struct {
        char nome[30], endereco[30];
        int idade;
    } Cadastro;

    FILE *arq = fopen("struct.txt", "wb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }

    Cadastro cad = {"John", "7th Avenue", 32};
    fwrite(&cad, sizeof(Cadastro), 1, arq);
    fclose(arq);

    return 0;
} */

/* Leitura de binario com um tipo de dado
int main() {
    FILE *arq = fopen("arquivo.txt", "rb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    int total_lido, v[5];
    total_lido = fread(v, sizeof(int), 5, arq);
    if(total_lido != 5) {
        printf("ERRO NA LEITURA");
        exit(1);
    }
    fclose(arq);
    printf("%d %d %d %d %d", v[0], v[1], v[2], v[3], v[4]);
    return 0;
} */

/* leitura de binario com varios tipos de dados
int main() {
    FILE *arq = fopen("dados.txt", "rb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char str[20];
    float x;
    int v[5];
    fread(str, sizeof(char), 20, arq);
    fread(&x, sizeof(float), 1, arq);
    fread(v, sizeof(int), 5, arq);
    printf("%s %f %d %d %d %d %d", str, x, v[0], v[1], v[2], v[3], v[4]);
    fclose(arq);
    return 0;
}*/

/* lendo struct em bin
int main() {
    typedef struct {
        char nome[30], endereco[30];
        int idade;
    } Cadastro;

    FILE *arq = fopen("struct.txt", "rb");
    if(arq == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }

    Cadastro cad;
    fread(&cad, sizeof(Cadastro), 1, arq);
    printf("%s %s %i", cad.nome, cad.endereco, cad.idade);
    fclose(arq);

    return 0;
} */

