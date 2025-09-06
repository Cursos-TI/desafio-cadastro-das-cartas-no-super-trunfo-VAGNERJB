#include <stdio.h>   
#include <string.h>  
#include <math.h>    
                    

// Definição da estrutura da Carta
typedef struct {
    char estado;              
    char codigo[10];          
    char nomeCidade[50];      
    int populacao;           
    float area;               
    float pib;                
    int pontosTuristicos;     
    float densidadePopulacional; 
    float pibPerCapita;          
    float superPoder;            
} Carta;


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler os dados de uma Carta
void lerCarta(Carta *carta, int numeroCarta) {
    printf("\n--- INICIANDO: CADASTRO DA CARTA %d ---\n", numeroCarta);

    printf("Estado da Carta %d (A-H): ", numeroCarta);
    scanf(" %c", &carta->estado); 
    
    printf("Codigo da Carta %d (ex: A01): ", numeroCarta);
    scanf("%s", carta->codigo);
    limparBuffer(); 

    printf("Nome da Cidade da Carta %d: ", numeroCarta);
    scanf(" %[^\n]%*c", carta->nomeCidade); 

    printf("Populacao da Carta %d: ", numeroCarta);
    scanf("%d", &carta->populacao);
    limparBuffer();

    printf("Area da Carta %d (em km2): ", numeroCarta);
    scanf("%f", &carta->area);
    limparBuffer();

    printf("PIB da Carta %d (em bilhoes): ", numeroCarta);
    scanf("%f", &carta->pib);
    limparBuffer();

    printf("Numero de Pontos Turisticos da Carta %d: ", numeroCarta);
    scanf("%d", &carta->pontosTuristicos);
    limparBuffer();
}


void calcularAtributosDerivados(Carta *carta) {
    
    carta->densidadePopulacional = (carta->area != 0) ? (float)carta->populacao / carta->area : 0.0;

   
    carta->pibPerCapita = (carta->populacao != 0) ? carta->pib / (float)carta->populacao : 0.0;

    
    float densidadeInvertida = 0.0;
    if (carta->densidadePopulacional > 0.0) {
        densidadeInvertida = 1.0 / carta->densidadePopulacional;
    } else {
        
        densidadeInvertida = 1.0e9; 
    }

    carta->superPoder = (float)carta->populacao + carta->area + carta->pib +
                        (float)carta->pontosTuristicos + carta->pibPerCapita +
                        densidadeInvertida;
}


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


int main() {
    // Declaração das duas cartas
    Carta carta1;
    Carta carta2;
    int resultadoComparacao; 

    // --- 1. Cadastro, Cálculo e Exibição da PRIMEIRA Carta ---
    lerCarta(&carta1, 1);
    calcularAtributosDerivados(&carta1);
    exibirCarta(carta1, 1);

    // --- 2. Cadastro, Cálculo e Exibição da SEGUNDA Carta ---
    lerCarta(&carta2, 2);
    calcularAtributosDerivados(&carta2);
    exibirCarta(carta2, 2);

   // Comparações das Cartas
    printf("\n--- INICIANDO: RESULTADOS DA COMPARACAO ---\n");
    printf("Regra: 1 se Carta 1 vence (melhor valor), 0 se Carta 2 vence ou empata.\n");
    printf("(Lembre-se: 'melhor valor' significa MAIOR para a maioria, mas MENOR para Densidade Populacional)\n\n");

    // Comparação para População: Maior População Ganha
    resultadoComparacao = (carta1.populacao > carta2.populacao) ? 1 : 0;
    printf("População: %d\n", resultadoComparacao);

    // Comparação para Area: Maior Area Ganha
    resultadoComparacao = (carta1.area > carta2.area) ? 1 : 0;
    printf("Área: %d\n", resultadoComparacao);
    
    // Comparação para PIB: Maior PIB Ganha
    resultadoComparacao = (carta1.pib > carta2.pib) ? 1 : 0;
    printf("PIB: %d\n", resultadoComparacao);

    // Comparação para Pontos Turisticos: Mais Pontos Turisticos Ganha
    resultadoComparacao = (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 0;
    printf("Pontos Turísticos: %d\n", resultadoComparacao);

    // Comparação para Densidade Populacional: MENOR VALOR GANHA
    resultadoComparacao = (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 0;
    printf("Densidade Populacional: %d\n", resultadoComparacao);

    // Comparação para PIB per Capita: Maior PIB per Capita Ganha
    resultadoComparacao = (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 0;
    printf("PIB per Capita: %d\n", resultadoComparacao);

    // Comparação para Super Poder: Maior Super Poder Ganha
    resultadoComparacao = (carta1.superPoder > carta2.superPoder) ? 1 : 0;
    printf("Super Poder: %d\n", resultadoComparacao);

    printf("\n----------------------------------------------------------\n");
    printf("\n--- FIM DO PROGRAMA ---\n");

    return 0; 
}