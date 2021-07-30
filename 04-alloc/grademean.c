#include<stdio.h>
#include<stdlib.h>

int main() {
    int total;
    do {
        printf("students total: ");
        scanf("%i", &total);

        if(total < 0) {
            printf("Entered value less than 0\n");
        }
    } while(total < 0);

    float *students = (float *) malloc(sizeof(float));

    int i;
    for(i = 0; i < total; i++) {
        do {
            printf("Enter the grade: ");
            scanf("%f", students + i);
            if(*(students + i) < 0 || *(students + i) > 10) {
                printf("Entered value less than 0 or greater than 10\n");
            }
        } while(*(students + i) < 0 || *(students + i) > 10);
    }

    float mean = 0;
    for(i = 0; i < total; i++) {
        mean += *(students + i);
    }

    free(students);
    students = NULL;

    mean = mean / total;
    printf("Class mean: %.2f", mean);

    return 0;
}