#include "quadro.h"

void asterisco_simples(int x, int y, char quadro[LINHAS][COLUNAS]);
void simbolo_soma(int x, int y, char quadro[LINHAS][COLUNAS]);
void letra_x(int x, int y, char quadro[LINHAS][COLUNAS]);
void gerar_posicao_aleatoria(int *x, int *y);
int posicao_livre(int x, int y, char quadro[LINHAS][COLUNAS], int tamanho);
void gerar_arte(int tipo_figura, int num_figuras);
void desenhar_raposa(char quadro[LINHAS][COLUNAS], int num_raposas);
void gerar_arte_raposa(int num_raposas, char quadro[LINHAS][COLUNAS]);