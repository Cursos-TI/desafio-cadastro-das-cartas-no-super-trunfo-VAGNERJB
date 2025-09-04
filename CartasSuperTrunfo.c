#include <stdio.h>   // Para funções de entrada e saída como printf e scanf
#include <string.h>  // Para funcoes de string como strcmp (ainda nao usado, mas util para nomes)
#include <math.h>    // Para fabs (não será usado para condicionais, mas pode ser útil para outros cálculos)

// --- DEFINICAO DA STRUCT E FUNCOES AUXILIARES ---

// Definição da struct para representar uma Carta
typedef struct {
    char estado;
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional; // Novo campo
    float pibPerCapita;          // Novo campo
    float superPoder;            // Novo campo
} Carta; // Agora você pode usar 'Carta' como um tipo

// Função auxiliar para limpar o buffer do teclado.
// É uma convenção comum em C para lidar com o '\n' deixado pelo scanf.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler os dados de uma Carta
void lerCarta(Carta *carta, int numeroCarta) {
    printf("\n--- INICIANDO: CADASTRO DA CARTA %d ---\n", numeroCarta);

    printf("Estado da Carta %d (A-H): ", numeroCarta);
    scanf(" %c", &carta->estado);
    limparBuffer();

    printf("Codigo da Carta %d (ex: A01): ", numeroCarta);
    scanf("%s", carta->codigo);
    limparBuffer();

    printf("Nome da Cidade da Carta %d: ");
    scanf(" %[^\n]%*c", carta->nomeCidade);

    printf("Populacao da Carta %d: ");
    scanf("%d", &carta->populacao);
    limparBuffer();

    printf("Area da Carta %d (em km2): ");
    scanf("%f", &carta->area);
    limparBuffer();

    printf("PIB da Carta %d (em bilhoes): ");
    scanf("%f", &carta->pib);
    limparBuffer();

    printf("Numero de Pontos Turisticos da Carta %d: ");
    scanf("%d", &carta->pontosTuristicos);
    limparBuffer();
}

// Função para calcular os atributos derivados (densidade, PIB per capita, super poder)
void calcularAtributosDerivados(Carta *carta) {
    // Cálculo da Densidade Populacional
    // Usa operador ternario para evitar divisao por zero, resultando em 0.0 se area for 0.
    carta->densidadePopulacional = (carta->area != 0) ? (float)carta->populacao / carta->area : 0.0;

    // Cálculo do PIB per capita
    // Usa operador ternario para evitar divisao por zero, resultando em 0.0 se populacao for 0.
    carta->pibPerCapita = (carta->populacao != 0) ? carta->pib / (float)carta->populacao : 0.0;

    // TODO: DEFINIR A FORMULA DO SUPER PODER
    // Por favor, substitua esta linha pela formula real que voce deseja usar.
    // Exemplo: carta->superPoder = (carta->populacao / 100000.0) + (carta->pib / 1.0) + (carta->pontosTuristicos * 5.0);
    carta->superPoder = 0.0; // Placeholder: POR FAVOR, DEFINA A FORMULA AQUI
}

// Função para exibir os dados de uma Carta, incluindo os novos atributos
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\n--- Dados da CARTA %d Cadastrados ---\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f bilhoes/hab\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
    printf("\n----------------------------------------------------------\n");
}

// --- FUNCAO PRINCIPAL ---
int main() {
    // --- 1. Cadastro, Cálculo e Exibição da PRIMEIRA Carta ---
    Carta carta1;
    lerCarta(&carta1, 1);
    calcularAtributosDerivados(&carta1);
    exibirCarta(carta1, 1);

    // --- 2. Cálculo da Média de 3 Notas (permanece igual) ---
    printf("\n--- INICIANDO: CALCULO DA MEDIA DE 3 NOTAS ---\n");
    int nota1, nota2, nota3;
    float media;

    printf("Digite a sua primeira nota: ");
    scanf("%d", &nota1);
    limparBuffer();

    printf("Digite a sua segunda nota: ");
    scanf("%d", &nota2);
    limparBuffer();

    printf("Digite a sua terceira nota: ");
    scanf("%d", &nota3);
    limparBuffer();

    media = (float)(nota1 + nota2 + nota3) / 3;
    printf("A media e = %.2f\n", media);
    printf("\n----------------------------------------------------------\n");

    // --- 3. Cadastro, Cálculo e Exibição da SEGUNDA Carta ---
    Carta carta2;
    lerCarta(&carta2, 2);
    calcularAtributosDerivados(&carta2);
    exibirCarta(carta2, 2);

    // --- 4. Comparações de Cartas ---
    printf("\n--- INICIANDO: COMPARACAO ENTRE CARTAS (Maior Valor Ganha) ---\n");
    printf("ATENCAO: Para Densidade Populacional, por favor, confirme a regra.\n");
    printf("\nComparando Carta 1 (%s) vs Carta 2 (%s):\n", carta1.nomeCidade, carta2.nomeCidade);

    // Comparação para População: Maior População Ganha
    printf("- Populacao: %s tem mais (%d vs %d)\n",
           (carta1.populacao > carta2.populacao ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.populacao, carta2.populacao);

    // Comparação para Area: Maior Area Ganha
    printf("- Area: %s tem mais (%.2f km2 vs %.2f km2)\n",
           (carta1.area > carta2.area ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.area, carta2.area);
    
    // Comparação para PIB: Maior PIB Ganha
    printf("- PIB: %s tem mais (%.2f bi vs %.2f bi)\n",
           (carta1.pib > carta2.pib ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.pib, carta2.pib);

    // Comparação para Pontos Turisticos: Mais Pontos Turisticos Ganha
    printf("- Pontos Turisticos: %s tem mais (%d vs %d)\n",
           (carta1.pontosTuristicos > carta2.pontosTuristicos ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.pontosTuristicos, carta2.pontosTuristicos);

    // Comparação para Densidade Populacional:
    // TODO: CONFIRME A REGRA AQUI. ASSUMINDO "MAIOR GANHA" POR ENQUANTO.
    printf("- Densidade Populacional: %s tem mais (%.2f hab/km2 vs %.2f hab/km2)\n",
           (carta1.densidadePopulacional > carta2.densidadePopulacional ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.densidadePopulacional, carta2.densidadePopulacional);

    // Comparação para PIB per Capita: Maior PIB per Capita Ganha
    printf("- PIB per Capita: %s tem mais (%.2f bi/hab vs %.2f bi/hab)\n",
           (carta1.pibPerCapita > carta2.pibPerCapita ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.pibPerCapita, carta2.pibPerCapita);

    // Comparação para Super Poder: Maior Super Poder Ganha
    // Este valor dependera da formula que voce definir para 'superPoder'
    printf("- Super Poder: %s tem mais (%.2f vs %.2f)\n",
           (carta1.superPoder > carta2.superPoder ? carta1.nomeCidade : carta2.nomeCidade),
           carta1.superPoder, carta2.superPoder);

    printf("\n----------------------------------------------------------\n");
    printf("\n--- FIM DO PROGRAMA ---\n");

    return 0; // Indica que o programa terminou com sucesso
}

