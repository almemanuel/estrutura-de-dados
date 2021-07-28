/*
fopen("nome fisico", "mode de abertura") -> cria um arquivo ou abre um existente
    Os modos de abertura são:
        r (read): o marcador é retornado ao inicio do arquivo. se não existe, retorna erro
        w (write): cria um arquivo para escrita. Se já existe, é sobrescrito
        a (append): adiciona conteudo ao fim do arquivo. se o arquivo não existe, é criado
fclose(arquivo) -> fecha um arquivo
getc(caractere, arquivo) -> lê um caracter de um arquivo
fgetc(arquivo) -> leem o caracter de um arquivo
fgets(string, tamanho, arquivo) -> lê um arquivo
fputc(caractere, arquivo) -> escreve um caracter em um arquivo
puts() -> escreve uma string em um arquivo
fputs(string, arquivo) -> escreve uma string em um arquivo
fprintf(arquivo, formatacao, variaveis) -> escreve um conjunto de dados em um arquivo
fscanf(arquivo, "formatacao", variaveis) -> lê um conjunto de dados de um arquivo
feof(arquivo) -> indica o fim de um arquivo

seek(arquivo, n, modo) -> movimenta-se byte a byte no arquivo
    n indica quantos bytes devem ser avançados ou retrocedidos. geralmente vem acompanhada de sizeof()
    modos:
        SEEK_SET -> parte do inicio e avança n bytes
        SEEK_END -> parte do final e retrocedo n bytes
        SEEK_CUR -> parte do local atual e avança n bytes

int fseek(FILE *fp, long offset, int origem);

int fwrite(buffer, tam_bytes, qtd, pont_arq)
fread(buffer, tam_bytes, qtd, pont_arq)
    buffer -> endereço de memoria onde deve ser lido ou escrito os valores
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int num;
    char nome[10];
    float nota;
} aluno;


int main() {
/*
    FILE *fp;
    aluno a, b;
    a.num = 100;
    strcpy(a.nome, "Aluno");
    a.nota = 9.5;
    fp = fopen("saidaBIN.bin", "wb"); // gravacao binario
    fwrite(&a, sizeof(aluno), 1,fp);
    fclose(fp);
    fp = fopen("saidaBin.bin", "rb"); // leitura binaria
    fread(&b, sizeof(aluno), 1, fp);
    printf("Dados gravados\nNum: %i, Nome: %s, nota = %.1f\n", b.num, b.nome, b.nota);
*/

    FILE *fp;
    int num[20];
    int vet[5];
    for(int i = 0; i < 20; i++)
        num[i] = i;
    fp = fopen("vetBin.bin", "wb"); // gravacao em bin
    fwrite(num, sizeof(int), 20,fp);
    fclose(fp);
    fp = fopen("vetBin.bin", "rb");
    fseek(fp, -5 * sizeof(int), SEEK_END);
    fread(vet, sizeof(int), 5,fp);
    printf("\nVetor resultante\n");
    for(int i = 0; i < 5; i++)
        printf("%i\t", vet[i]);

    return 0;
}