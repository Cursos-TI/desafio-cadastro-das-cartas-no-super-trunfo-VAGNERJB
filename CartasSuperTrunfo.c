#include <stdio.h> // Para funções de entrada e saída como printf e scanf
#include <math.h>  // Para fabs, embora a condicional com ele será removida

// Função auxiliar para limpar o buffer do teclado.
// É uma convenção comum em C para lidar com o '\n' deixado pelo scanf.
// Internamente, ela usa um loop, mas é uma utilidade e não parte da lógica de negócio principal.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // --- 1. Cadastro e Exibição da PRIMEIRA Carta ---
    printf("\n--- INICIANDO: CADASTRO E EXIBICAO DA PRIMEIRA CARTA ---\n");
    char estado1;
    char codigo1[10];        // Espaço para 9 caracteres + o terminador nulo '\0'
    char nomeCidade1[50];    // Espaço para 49 caracteres + o terminador nulo '\0'
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    printf("Estado da Carta 1 (A-H): ");
    scanf(" %c", &estado1);
    limparBuffer(); // Limpa buffer apos ler char

    printf("Codigo da Carta 1 (ex: A01): ");
    scanf("%s", codigo1);
    limparBuffer(); // Limpa buffer apos ler string

    printf("Nome da Cidade da Carta 1: ");
    // %[^\n]%*c le a linha inteira, incluindo espacos, e ja consome o '\n' final
    scanf(" %[^\n]%*c", nomeCidade1); 

    printf("Populacao da Carta 1: ");
    scanf("%d", &populacao1);
    limparBuffer();

    printf("Area da Carta 1 (em km2): ");
    scanf("%f", &area1);
    limparBuffer();

    printf("PIB da Carta 1 (em bilhoes): ");
    scanf("%f", &pib1);
    limparBuffer();

    printf("Numero de Pontos Turisticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);
    limparBuffer();

    printf("\n--- Dados da PRIMEIRA Carta Cadastrados ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("\n----------------------------------------------------------\n");

    // --- 2. Cálculo da Média de 3 Notas ---
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

    // --- 3. Cadastro e Exibição da SEGUNDA Carta ---
    printf("\n--- INICIANDO: CADASTRO E EXIBICAO DA SEGUNDA CARTA ---\n");
    char estado2;
    char codigo2[10];        
    char nomeCidade2[50];    
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
     
    printf("Estado da Carta 2 (A-H): ");
    scanf(" %c", &estado2);
    limparBuffer();

    printf("Codigo da Carta 2 (ex: B02): ");
    scanf("%s", codigo2);
    limparBuffer();

    printf("Nome da Cidade da Carta 2: ");
    scanf(" %[^\n]%*c", nomeCidade2);
    
    printf("Populacao da Carta 2: ");
    scanf("%d", &populacao2);
    limparBuffer();
    
    printf("Area da Carta 2 (em km2): ");
    scanf("%f", &area2);
    limparBuffer();
    
    printf("PIB da Carta 2 (em bilhoes): ");
    scanf("%f", &pib2);
    limparBuffer();
    
    printf("Numero de Pontos Turisticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);
    limparBuffer();
  
    printf("\n--- Dados da SEGUNDA Carta Cadastrados ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("\n----------------------------------------------------------\n");

    // --- 4. Cálculo de Densidade Populacional (Sem comparações ou tratamento de erro) ---
    printf("\n--- INICIANDO: CALCULO DE DENSIDADE POPULACIONAL ---\n");
    printf("ATENCAO: Este programa nao pode usar condicionais. Se voce digitar 0 para a area, o programa pode exibir 'inf' ou 'NaN' ou ate mesmo travar devido a divisao por zero.\n");
    float populacao_a, area_a, populacao_b, area_b;
    float razao_a, razao_b;

    printf("Digite a populacao e area da Regiao A (separadas por espaco): ");
    scanf("%f %f", &populacao_a, &area_a);
    limparBuffer();

    printf("Digite a populacao e area da Regiao B (separadas por espaco): ");
    scanf("%f %f", &populacao_b, &area_b);
    limparBuffer();

    // Nao ha verificacao de area_a == 0 ou area_b == 0
    razao_a = populacao_a / area_a;
    razao_b = populacao_b / area_b;

    printf("\nRegiao A: Populacao/Area = %.2f\n", razao_a);
    printf("Regiao B: Populacao/Area = %.2f\n", razao_b);

    // Nao ha comparacoes do tipo "maior", "menor" ou "aproximadamente iguais"
    printf("\n--- FIM DO PROGRAMA ---\n");

    return 0; // Indica que o programa terminou com sucesso
}