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
    printf("Digite o estado da carta #%d: ", num);
    scanf(" %[^\n]", estado);
    printf("Digite o código da carta #%d: ", num);
    scanf(" %[^\n]", codigo);
    printf("Digite o nome da cidade da carta #%d: ", num);
    scanf(" %[^\n]", cidade);
    printf("Digite a população da carta #%d: ", num);
    scanf("%lu", pop);
    printf("Digite a área da carta #%d: ", num);
    scanf("%f", area);
    printf("Digite o PIB da carta #%d: ", num);
    scanf("%f", pib);
    printf("Digite o número de pontos turísticos da carta #%d: ", num);
    scanf("%d", pt);
}

int main() {
    char estado1[50], codigo1[10], cidade1[50];
    unsigned long int pop1;
    float area1, pib1;
    int pt1;

    char estado2[50], codigo2[10], cidade2[50];
    unsigned long int pop2;
    float area2, pib2;
    int pt2;

    lerCarta(estado1, codigo1, cidade1, &pop1, &area1, &pib1, &pt1, 1);
    lerCarta(estado2, codigo2, cidade2, &pop2, &area2, &pib2, &pt2, 2);
    
    int atributo = 0;
    printf("\nSELECIONE O ATRIBUTO PARA COMPARAÇÃO:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    if (atributo < 1 || atributo > 7) {
        printf("Atributo inválido!\n");
        return 1;
    }
    switch(atributo) {
        case 1:
            printf("Comparando pelo atributo: População\n");
            printf("Carta 1 - %s: %lu habitantes\n", estado1, pop1);
            printf("Carta 2 - %s: %lu habitantes\n", estado2, pop2);
            if (pop1 > pop2) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (pop2 > pop1) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Comparando pelo atributo: Área\n");
            printf("Carta 1 - %s: %.2f km²\n", estado1, area1);
            printf("Carta 2 - %s: %.2f km²\n", estado2, area2);
            if (area1 > area2) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (area2 > area1) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Comparando pelo atributo: PIB\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", estado1, pib1);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", estado2, pib2);
            if (pib1 > pib2) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (pib2 > pib1) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("Comparando pelo atributo: Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", estado1, pt1);
            printf("Carta 2 - %s: %d pontos\n", estado2, pt2);
            if (pt1 > pt2) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (pt2 > pt1) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("Comparando pelo atributo: Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", estado1, (float)pop1 / area1);
            printf("Carta 2 - %s: %.2f hab/km²\n", estado2, (float)pop2 / area2);
            if ((pop1 / area1) < (pop2 / area2)) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if ((pop2 / area2) < (pop1 / area1)) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 6:
            printf("Comparando pelo atributo: PIB per Capita\n");
            printf("Carta 1 - %s: %.2f reais\n", estado1, (pib1 * 1000000000) / pop1);
            printf("Carta 2 - %s: %.2f reais\n", estado2, (pib2 * 1000000000) / pop2);
            if (((pib1 * 1000000000) / pop1) > ((pib2 * 1000000000) / pop2)) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (((pib2 * 1000000000) / pop2) > ((pib1 * 1000000000) / pop1)) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        case 7: {
            float superPoder1 = pop1 + area1 + pib1 + pt1 + ((float)1 / ((float)pop1 / area1));
            float superPoder2 = pop2 + area2 + pib2 + pt2 + ((float)1 / ((float)pop2 / area2));
            printf("Comparando pelo atributo: Super Poder\n");
            printf("Carta 1 - %s: %.2f\n", estado1, superPoder1);
            printf("Carta 2 - %s: %.2f\n", estado2, superPoder2);
            if (superPoder1 > superPoder2) {
                printf("Vencedora: Carta 1 (%s)\n", estado1);
            } else if (superPoder2 > superPoder1) {
                printf("Vencedora: Carta 2 (%s)\n", estado2);
            } else {
                printf("Empate!\n");
            }
            break;
        }
        default:
            printf("Atributo inválido!\n");
            break;
    }
    return 0;
}