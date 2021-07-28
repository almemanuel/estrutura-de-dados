#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
string é uma cadeia de caracteres finalizada com o símbolo "\0"
em C, um caracter possui 8 bits, e é um tipo primitivo
inteiro também é um tipo primitivo, porém, varia o tamanho de acordo com a cpu
    embora isso possa trazer problemas, a motivação é a eficiência do programa
    inteiros podem ser signed (-128 a 127) ou unsigned (0 a 255)
    em signed, o MSB possui o sinal, sendo que 1 indica negativo e 0 indica positivo
    Por exemplo, para executar a subtração 15-5, o computador fará o seguinte
    15 -> 0000 1111
    5  -> 0000 0101 -, mas, para aproveitar o mesmo circuito, ele utiliza complemento de dois
    Logo, o correto é:
    15 -> 0000 1111
    5  -> 1111 1011 +
    10 -> 0000 1010
float é outro tipo primitivo
    aproximação -> IEEE 754 defini o ponto flutuante
        possui o valor de sinal, 2 pelo expoente (parte inteira) e a fração (mantiça na base 2)
        existe um erro de precisão no armazenamento de valores flutuantes
        em C, o float possui 32 bits e o double 64 bits
Array é uma lista de elementos
    sempre que chamamos o array, estamos chamando o endereço do primeiro elemento
    ele aloca elementos lado a lado e possui tamanho fixo
    por serem do mesmo tipo, cada elemento possui exatamente o mesmo comprimento
Tudo o que é alocado na memória possui um endereço
*/

/*
void f2(char hello[]) {
    printf("from f2: %d\n", &hello);
    printf("%s\n", hello);
}

void f1(char hello[]) {
    printf("from f1: %d\n", &hello);
    f2(hello);
}

int main() {
    char hello[] = "Hello World";

    printf("from main: %d\n", &hello);
    f1(hello);

    return 0;
}

passando o parametro por cópia, temos vários endereços para a mesma coisa

recursão pode estourar a stack (vazamento de memória) se mal implementada

void f3(char hello[]) {
    printf("from f1: %d\n", &hello);
    f3(hello);
}

int main() {
    char hello[] = "Hello World";

    printf("from main: %d\n", &hello);
    f3(hello);

    return 0;
}

a recursão vai empilhando vários endereços, pois, nesta situação, está sendo alocados novos endereços

o ponteiro permite minimizar vários desses problemas

int main() {
    char hello[] = "Hello World";
    printf("from main: %d\n", &hello);

    char *hello2 = malloc(sizeof(hello));
    strcpy(hello2, hello);
    printf("hello2: %x\n", hello2);

    char *hello3 = hello2 + 6;
    printf("from hello2: %s\n", hello2);
    printf("from hello3: %s\n", hello3);

    return 0;
}

neste exemplo, temos apenas duas variaveis sendo apontadas por ponteiros
*/

/*
struct permite criar elementos de tipo diferentes que são concatenados

struct Person {
    char name[10];
    int age;
    int height;
}

void main() {
    struct Person person;
    strcpy(person.nome, "Fabio");
    person.age = 43;
    person.height = 172;

    return 0;
}
*/

/*
para o binário, nada precisa ter nome para existir, tudo são bits
*/
struct Person {
    char name[10];
    int age;
    int height;
};

void createPerson(char name[], int age, int height, void(*function_pointer)(struct Person)) {
    struct Person person;
    strcpy(person.name, name);
    person.age = age;
    person.height = height;

    (*function_pointer)(person);
}

void printPerson(struct Person person) {
    printf("Person: %s %d %d\n", person.name, person.age, person.height);
}

void printPerson2(struct Person person) {
    printf("name: %s age: %d height: %d\n", person.name, person.age, person.height);
}

int main() {
    createPerson("Emanuel", 23, 173, &printPerson);
    createPerson("Emanuel", 23, 173, &printPerson2);

    return 0;
}