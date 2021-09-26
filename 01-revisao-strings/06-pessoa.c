/***************************************************************************
Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o
nome da pessoa e a palavra “ACEITA”, caso contrário imprimir “NÃO ACEITA”.
***************************************************************************/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char gender;
    int age;
} Person;

int ageValidate(int age);
char genderValidate(char gender);
int accept(Person user);

int main() {
    Person user;

    printf("Name: ");
    fgets(user.name, 50, stdin);
    setbuf(stdin, NULL);

    printf("\n\tM - Male\n\tF - Female\nGender: ");
    scanf("%c", &user.gender);
    setbuf(stdin, NULL);
    user.gender = genderValidate(toupper(user.gender));

    printf("Age: ");
    scanf("%i", &user.age);
    user.age = ageValidate(user.age);

    if(accept(user)) {
        printf("ACEITO\n");
    } else {
        printf("NAO ACEITO\n");
    }

    return 0;
}

int ageValidate(int age) {
    if (age > 0) {
        return age;
    }
    printf("INVALID AGE! Try again\n\tAge: ");
    scanf("%i", &age);
    return ageValidate(age);
}

char genderValidate(char gender) {
    if (gender == 'F' || gender == 'M') {
        return gender;
    }
    printf("INVALID GENDER! Try again\n\tGender: ");
    scanf("%s", &gender);
    return genderValidate(toupper(gender));
}

int accept(Person user) {
    if(user.age < 25 && user.gender == 'F') {
        return 1;
    }
    return 0;
}