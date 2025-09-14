#include <stdio.h>

int END = 0;

float breakrow(){
    printf("\n");
}

float make_media_from_notas(float nota1, float nota2, float nota3, float nota4){
    return (float)(nota1 + nota2 + nota3 + nota4) / 4;
}

int main() {
    float nota1 , nota2, nota3, nota4;

    printf("Bem-vindo, para saber sua média digite elas!");
    breakrow();

    printf("Nota 1: ");
    scanf("%f", &nota1);
    breakrow();

    printf("Nota 2: ");
    scanf("%f", &nota2);
    breakrow();

    printf("Nota 3: ");
    scanf("%f", &nota3);
    breakrow();

    printf("Nota 4: ");
    scanf("%f", &nota4);
    breakrow();

    printf("Sua média é: %f", make_media_from_notas(nota1, nota2, nota3, nota4));
    breakrow();

    return END;
}
