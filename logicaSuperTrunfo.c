#include <stdio.h>

int main() {
    // Variáveis
    char continente1 = 'A', continente2 = 'E';
    char carta1[] = "A01", carta2[] = "E01", pais1[] = "Brasil", pais2[] = "Franca";
    int populacao1 = 214000000, populacao2 = 68000000;
    int pturistico1 = 10, pturistico2 = 12;
    float pib1 = 2080000000000, pib2 = 3100000000000;
    float area1 = 8515767, area2 = 643801;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibpercapita1 = pib1 / populacao1;
    float pibpercapita2 = pib2 / populacao2;
    float superpd1 = populacao1 + pturistico1 + pib1 + area1 + pibpercapita1 + (1 / densidade1);
    float superpd2 = populacao2 + pturistico2 + pib2 + area2 + pibpercapita2 + (1 / densidade2);

    int atributo1, atributo2;
    char *nomes_atributos[] = {"", "Populacao", "Area", "Densidade", "PIB", "Pontos Turisticos", "PIB per capita", "Super Poder"};
    //iniciando o jogo
    printf("### BEM VINDO AO JOGO SUPER TRUNFO ####\n");
    printf("Digite o primeiro atributo para comparar:\n");
    // coletando as entradas
    printf("1. Populacao\n2. Area\n3. Densidade\n4. PIB\n5. Pontos Turisticos\n6. PIB per capita\n7. Super Poder\n");
    scanf("%d", &atributo1);

    printf("Digite o segundo atributo para comparar:\n");
    if (atributo1 != 1) printf("1. Populacao\n");
    if (atributo1 != 2) printf("2. Area\n");
    if (atributo1 != 3) printf("3. Densidade\n");
    if (atributo1 != 4) printf("4. PIB\n");
    if (atributo1 != 5) printf("5. Pontos Turisticos\n");
    if (atributo1 != 6) printf("6. PIB per capita\n");
    if (atributo1 != 7) printf("7. Super Poder\n");
    scanf("%d", &atributo2);

    // Funcoes de comparacao
    int comp1 = 0, comp2 = 0;
    float val1_a = 0, val2_a = 0, val1_b = 0, val2_b = 0;
    switch (atributo1) {
        case 1: val1_a = populacao1; val2_a = populacao2; break;
        case 2: val1_a = area1; val2_a = area2; break;
        case 3: val1_a = densidade1; val2_a = densidade2; break;
        case 4: val1_a = pib1; val2_a = pib2; break;
        case 5: val1_a = pturistico1; val2_a = pturistico2; break;
        case 6: val1_a = pibpercapita1; val2_a = pibpercapita2; break;
        case 7: val1_a = superpd1; val2_a = superpd2; break;
        default: printf("Atributo 1 invalido\n"); return 0;
    }

    switch (atributo2) {
        case 1: val1_b = populacao1; val2_b = populacao2; break;
        case 2: val1_b = area1; val2_b = area2; break;
        case 3: val1_b = densidade1; val2_b = densidade2; break;
        case 4: val1_b = pib1; val2_b = pib2; break;
        case 5: val1_b = pturistico1; val2_b = pturistico2; break;
        case 6: val1_b = pibpercapita1; val2_b = pibpercapita2; break;
        case 7: val1_b = superpd1; val2_b = superpd2; break;
        default: printf("Atributo 2 invalido\n"); return 0;
    }
    // criando exceção para densidade
    if (atributo1 == 3)
        comp1 = (val1_a < val2_a) ? 1 : 2;
    else
        comp1 = (val1_a > val2_a) ? 1 : 2;

    if (atributo2 == 3)
        comp2 = (val1_b < val2_b) ? 1 : 2;
    else
        comp2 = (val1_b > val2_b) ? 1 : 2;
    //Gerando os resultados

    printf("\n--- Resultado ---\n");
    printf("Carta 1 (%s - %s): \n (%s) %.2f \n (%s) %.2f\n", carta1, pais1, nomes_atributos[atributo1], val1_a, nomes_atributos[atributo2],val1_b);
    printf("Carta 2 (%s - %s): \n (%s) %.2f \n (%s) %.2f\n", carta2, pais2, nomes_atributos[atributo1], val2_a, nomes_atributos[atributo2], val2_b);

    printf("Comparacao 1 (%s): %s\n", nomes_atributos[atributo1], (comp1 == 1) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Comparacao 2 (%s): %s\n", nomes_atributos[atributo2], (comp2 == 1) ? "Carta 1 venceu" : "Carta 2 venceu");

    if (comp1 == comp2)
        printf("Resultado Final: Carta %d VENCEU!\n", comp1);
    else
        printf("Resultado Final: EMPATE!\n");

    return 0;
}
