#include <stdio.h>

int END = 0;

int main() {

    // carta #1
    char estado_carta_um[20];
    char codigo_carta_um[3];
    char cidade_nome_carta_um[50];
    int populacao_carta_um;
    float area_carta_um;
    float pib_carta_um;
    int numero_pontos_turisticos_carta_um;

    // carta #2
    char estado_carta_dois[20];
    char codigo_carta_dois[3];
    char cidade_nome_carta_dois[50];
    int populacao_carta_dois;
    float area_carta_dois;
    float pib_carta_dois;
    int numero_pontos_turisticos_carta_dois;


    printf("começando a criação da carta #1 \n");
    printf("digite o estado da carta #1: \n");
    scanf("%s", estado_carta_um);

    printf("digite o codigo da carta #1: \n");
    scanf("%s", codigo_carta_um);

    printf("digite o nome cidade da carta #1: \n");
    scanf(" %[^\n]", cidade_nome_carta_um);

    printf("digite a população da carta #1: \n");
    scanf("%d", &populacao_carta_um);

    printf("digite a área da carta #1: \n");
    scanf("%f", &area_carta_um);

    printf("digite o PIB da carta #1: \n");
    scanf("%f", &pib_carta_um);

    printf("digite o número de pontos turisticos da carta #1: \n");
    scanf("%d", &numero_pontos_turisticos_carta_um);
    
    printf("começando a criação da carta #2 \n");
    printf("digite o estado da carta #2: \n");
    scanf("%s", estado_carta_dois);

    printf("digite o codigo da carta #2: \n");
    scanf("%s", codigo_carta_dois);

    printf("digite o nome cidade da carta #2: \n");
    scanf(" %[^\n]", cidade_nome_carta_dois);

    printf("digite a população da carta #2: \n");
    scanf("%d", &populacao_carta_dois);

    printf("digite a área da carta #2: \n");
    scanf("%f", &area_carta_dois);

    printf("digite o PIB da carta #2: \n");
    scanf("%f", &pib_carta_dois);

    printf("digite o número de pontos turisticos da carta #2: \n");
    scanf("%d", &numero_pontos_turisticos_carta_dois);

    printf("\n\n");
    printf("Carta 1:\n\n");
    printf("Estado: %s\n", estado_carta_um);
    printf("Código: %s\n", codigo_carta_um);
    printf("Nome da Cidade: %s\n", cidade_nome_carta_um);
    printf("População: %d\n", populacao_carta_um);
    printf("Área: %.2f km²\n", area_carta_um);
    printf("PIB: %.2f bilhões de reais\n", pib_carta_um);
    printf("Número de Pontos Turísticos: %d\n", numero_pontos_turisticos_carta_um);
    printf("Densidade Populacional: %.2f hab/km²\n", (float) populacao_carta_um / area_carta_um);
    printf("PIB per Capita: %.2f reais\n", (pib_carta_um * 1000000000) / populacao_carta_um);
    printf("\n");

    printf("Carta 2:\n\n");
    printf("Estado: %s\n", estado_carta_dois);
    printf("Código: %s\n", codigo_carta_dois);
    printf("Nome da Cidade: %s\n", cidade_nome_carta_dois);
    printf("População: %d\n", populacao_carta_dois);
    printf("Área: %.2f km²\n", area_carta_dois);
    printf("PIB: %.2f bilhões de reais\n", pib_carta_dois);
    printf("Número de Pontos Turísticos: %d\n", numero_pontos_turisticos_carta_dois);
    printf("Densidade Populacional: %.2f hab/km²\n", (float) populacao_carta_dois / area_carta_dois);
    printf("PIB per Capita: %.2f reais\n", (pib_carta_dois * 1000000000) / populacao_carta_dois);
    
    return 0;
}