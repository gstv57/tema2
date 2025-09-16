#include <stdio.h>

void printCarta(char *estado, char *codigo, char *cidade, unsigned long int populacao, float area, float pib, int pontoTuristico) {
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontoTuristico);
    printf("Densidade Populacional: %.2f hab/km²\n", (float) populacao / area);
    printf("PIB per Capita: %.2f reais\n", (pib * 1000000000) / populacao);
}

void compararCartas(
    char *estado1, char *codigo1, char *cidade1, unsigned long int pop1, float area1, float pib1, int pt1,
    char *estado2, char *codigo2, char *cidade2, unsigned long int pop2, float area2, float pib2, int pt2
) {
    float superPoder1 = pop1 + area1 + pib1 + pt1 + ((float)1 / ((float)pop1 / area1));
    float superPoder2 = pop2 + area2 + pib2 + pt2 + ((float)1 / ((float)pop2 / area2));

    printf("Comparação de Cartas \n");
    printf("População: Carta %d venceu (%d)\n", (pop1 > pop2) ? 1 : 2, (pop1 > pop2) ? 1 : 0);
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2) ? 1 : 2, (area1 > area2) ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, (pib1 > pib2) ? 1 : 0);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (pt1 > pt2) ? 1 : 2, (pt1 > pt2) ? 1 : 0);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", ((pop1 / area1) < (pop2 / area2)) ? 1 : 2, ((pop1 / area1) < (pop2 / area2)) ? 1 : 0);
    printf("PIB per Capita: Carta %d venceu (%d)\n", ((pib1 * 1000000000 / pop1) > (pib2 * 1000000000 / pop2)) ? 1 : 2, ((pib1 * 1000000000 / pop1) > (pib2 * 1000000000 / pop2)) ? 1 : 0);
    printf("Super Poder: Carta %d venceu (%d)\n", (superPoder1 > superPoder2) ? 1 : 2, (superPoder1 > superPoder2) ? 1 : 0);

    printf("\n");
    printf("Resumo do Super Poder:\n");
    printf("Carta 1 - Super Poder: %.2f\n", superPoder1);
    printf("Carta 2 - Super Poder: %.2f\n", superPoder2);
    
    if (superPoder1 > superPoder2) {
        printf("Carta 1 é a vencedora geral!\n");
    } else if (superPoder2 > superPoder1) {
        printf("Carta 2 é a vencedora geral!\n");
    } else {
        printf("As cartas estão empatadas!\n");
    }


    printf("\n");
    printf("Comparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s População de %lu\n", estado1, pop1);
    printf("Carta 2 - %s População de %lu\n", estado2, pop2);

    if(pop1 > pop2) {
        printf("Resultado: Carta 1 %s venceu! \n", estado1);
    } else if(pop2 > pop1) {
        printf("Resultado: Carta 2 %s venceu! \n", estado2);
    } else {
        printf("Resultado: Empate! Ambas as cartas têm população de %lu \n", pop1);
    }
}

void lerCarta(char *estado, char *codigo, char *cidade, unsigned long int *pop, float *area, float *pib, int *pt, int num) {
    printf("começando a criação da carta #%d \n", num);
    printf("digite o estado da carta #%d: \n", num);
    scanf("%s", estado);
    printf("digite o codigo da carta #%d: \n", num);
    scanf("%s", codigo);
    printf("digite o nome cidade da carta #%d: \n", num);
    scanf(" %[^\n]", cidade);
    printf("digite a população da carta #%d: \n", num);
    scanf("%lu", pop);
    printf("digite a área da carta #%d: \n", num);
    scanf("%f", area);
    printf("digite o PIB da carta #%d: \n", num);
    scanf("%f", pib);
    printf("digite o número de pontos turisticos da carta #%d: \n", num);
    scanf("%d", pt);
}

int main() {
    char estado1[20], codigo1[3], cidade1[50];
    unsigned long int pop1;
    float area1, pib1;
    int pt1;

    char estado2[20], codigo2[3], cidade2[50];
    unsigned long int pop2;
    float area2, pib2;
    int pt2;

    lerCarta(estado1, codigo1, cidade1, &pop1, &area1, &pib1, &pt1, 1);
    lerCarta(estado2, codigo2, cidade2, &pop2, &area2, &pib2, &pt2, 2);

    printf("\n\nCarta 1:\n\n");
    printCarta(estado1, codigo1, cidade1, pop1, area1, pib1, pt1);
    printf("\nCarta 2:\n\n");
    printCarta(estado2, codigo2, cidade2, pop2, area2, pib2, pt2);
    printf("\n");
    compararCartas(estado1, codigo1, cidade1, pop1, area1, pib1, pt1, estado2, codigo2, cidade2, pop2, area2, pib2, pt2);

    return 0;
}