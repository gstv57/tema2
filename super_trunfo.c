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

void exibirMenuAtributos(int atributoExcluido) {
    printf("\nESCOLHA UM ATRIBUTO PARA COMPARAÇÃO:\n");
    if (atributoExcluido != 1) printf("1 - População\n");
    if (atributoExcluido != 2) printf("2 - Área\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade Demográfica\n");
    if (atributoExcluido != 6) printf("6 - PIB per Capita\n");
    printf("Digite o número do atributo: ");
}

float obterValorAtributo(int atributo, unsigned long int pop, float area, float pib, int pt) {
    if (atributo == 1) return (float)pop;
    if (atributo == 2) return area;
    if (atributo == 3) return pib;
    if (atributo == 4) return (float)pt;
    if (atributo == 5) return (float)pop / area;
    if (atributo == 6) return (pib * 1000000000) / pop;
    return 0.0;
}

char* obterNomeAtributo(int atributo) {
    if (atributo == 1) return "População";
    if (atributo == 2) return "Área";
    if (atributo == 3) return "PIB";
    if (atributo == 4) return "Pontos Turísticos";
    if (atributo == 5) return "Densidade Demográfica";
    if (atributo == 6) return "PIB per Capita";
    return "Desconhecido";
}

char* obterUnidadeAtributo(int atributo) {
    if (atributo == 1) return "habitantes";
    if (atributo == 2) return "km²";
    if (atributo == 3) return "bilhões de reais";
    if (atributo == 4) return "pontos";
    if (atributo == 5) return "hab/km²";
    if (atributo == 6) return "reais";
    return "";
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
    
    int atributo1 = 0;
    do {
        exibirMenuAtributos(0); // Sem exclusão na primeira escolha
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 6) {
            printf("Atributo inválido! Escolha entre 1 e 6.\n");
        }
    } while (atributo1 < 1 || atributo1 > 6);
    
    int atributo2 = 0;
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        exibirMenuAtributos(atributo1); // Excluindo o primeiro atributo
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Atributo inválido ou já escolhido! Escolha um atributo diferente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);
    
    float valor1_carta1 = obterValorAtributo(atributo1, pop1, area1, pib1, pt1);
    float valor1_carta2 = obterValorAtributo(atributo1, pop2, area2, pib2, pt2);
    float valor2_carta1 = obterValorAtributo(atributo2, pop1, area1, pib1, pt1);
    float valor2_carta2 = obterValorAtributo(atributo2, pop2, area2, pib2, pt2);
    
    int vencedor_attr1, vencedor_attr2;
    
    if (atributo1 == 5) {
        if (valor1_carta1 < valor1_carta2) {
            vencedor_attr1 = 1;
        } else if (valor1_carta1 > valor1_carta2) {
            vencedor_attr1 = 2;
        } else {
            vencedor_attr1 = 0;
        }
    } else {
        if (valor1_carta1 > valor1_carta2) {
            vencedor_attr1 = 1;
        } else if (valor1_carta1 < valor1_carta2) {
            vencedor_attr1 = 2;
        } else {
            vencedor_attr1 = 0;
        }
    }
    
    if (atributo2 == 5) {
        if (valor2_carta1 < valor2_carta2) {
            vencedor_attr2 = 1;
        } else if (valor2_carta1 > valor2_carta2) {
            vencedor_attr2 = 2;
        } else {
            vencedor_attr2 = 0;
        }
    } else {
        if (valor2_carta1 > valor2_carta2) {
            vencedor_attr2 = 1;
        } else if (valor2_carta1 < valor2_carta2) {
            vencedor_attr2 = 2;
        } else {
            vencedor_attr2 = 0;
        }
    }
    
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;
    
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("Carta 1: %s\n", estado1);
    printf("Carta 2: %s\n", estado2);
    printf("\nAtributos escolhidos: %s e %s\n", obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
    
    printf("\n--- Comparacao por %s ---\n", obterNomeAtributo(atributo1));
    printf("Carta 1 (%s): %.2f %s\n", estado1, valor1_carta1, obterUnidadeAtributo(atributo1));
    printf("Carta 2 (%s): %.2f %s\n", estado2, valor1_carta2, obterUnidadeAtributo(atributo1));
    if (vencedor_attr1 == 1) {
        printf("Vencedor: Carta 1 (%s)\n", estado1);
    } else if (vencedor_attr1 == 2) {
        printf("Vencedor: Carta 2 (%s)\n", estado2);
    } else {
        printf("Empate!\n");
    }
    
    printf("\n--- Comparacao por %s ---\n", obterNomeAtributo(atributo2));
    printf("Carta 1 (%s): %.2f %s\n", estado1, valor2_carta1, obterUnidadeAtributo(atributo2));
    printf("Carta 2 (%s): %.2f %s\n", estado2, valor2_carta2, obterUnidadeAtributo(atributo2));
    if (vencedor_attr2 == 1) {
        printf("Vencedor: Carta 1 (%s)\n", estado1);
    } else if (vencedor_attr2 == 2) {
        printf("Vencedor: Carta 2 (%s)\n", estado2);
    } else {
        printf("Empate!\n");
    }
    
    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    printf("Carta 1 (%s): %.2f + %.2f = %.2f\n", estado1, valor1_carta1, valor2_carta1, soma_carta1);
    printf("Carta 2 (%s): %.2f + %.2f = %.2f\n", estado2, valor1_carta2, valor2_carta2, soma_carta2);
    
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDORA: Carta 1 (%s) com soma %.2f!\n", estado1, soma_carta1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDORA: Carta 2 (%s) com soma %.2f!\n", estado2, soma_carta2);
    } else {
        printf("EMPATE! Ambas as cartas tem soma %.2f\n", soma_carta1);
    }
    return 0;
}