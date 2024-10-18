#include "quadro.h"


// Função para criar o quadro com bordas
void criar_quadro(char quadro[LINHAS][COLUNAS]) {
    // Criar primeira e última linha com '-' em todas as colunas
    for (int i = 0; i < COLUNAS; i++) {
        quadro[0][i] = '-';
        quadro[LINHAS - 1][i] = '-';
    }
    // Criar linhas intermediárias com '|' nas bordas e espaços no meio
    for (int i = 1; i < LINHAS - 1; i++) {
        quadro[i][0] = '|';
        for (int j = 1; j < COLUNAS - 1; j++) {
            quadro[i][j] = ' ';
        }
        quadro[i][COLUNAS - 1] = '|';
    }
}

// Função para imprimir o quadro
void imprimir_quadro(char quadro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
}