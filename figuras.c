#include "figuras.h"

// Funções para desenhar as figuras
void asterisco_simples(int x, int y, char quadro[LINHAS][COLUNAS]) {
    quadro[x][y] = '*';
}

void simbolo_soma(int x, int y, char quadro[LINHAS][COLUNAS]) {
    if (x > 1 && x < LINHAS - 1 && y > 1 && y < COLUNAS - 1) {
        quadro[x - 1][y] = '*';
        quadro[x][y - 1] = '*';
        quadro[x][y] = '*';
        quadro[x][y + 1] = '*';
        quadro[x + 1][y] = '*';
    }
}

void letra_x(int x, int y, char quadro[LINHAS][COLUNAS]) {
    if (x > 1 && x < LINHAS - 1 && y > 1 && y < COLUNAS - 1) {
        quadro[x - 1][y - 1] = '*';
        quadro[x - 1][y + 1] = '*';
        quadro[x][y] = '*';
        quadro[x + 1][y - 1] = '*';
        quadro[x + 1][y + 1] = '*';
    }
}

// Função para gerar posições aleatórias para as figuras
void gerar_posicao_aleatoria(int *x, int *y) {
    *y = rand() % (COLUNAS - 2) + 1; // Garante que as figuras estejam dentro do quadro, adiciona 1 para garantir que o resultado nao sera 0
    *x = rand() % (LINHAS - 2) + 1; //Linhas - 2 e colunas - 2 é para garantir que não fique na borda do quadro
}

// Função para verificar se a posição está livre (para figuras de 3x3, ou 1x1 no caso do asterisco)
int posicao_livre(int x, int y, char quadro[LINHAS][COLUNAS], int tamanho) {
    
    // Verifica se a posição inicial e o tamanho estão dentro dos limites do quadro.
    if ((x-1) + tamanho >= LINHAS - 1 || (y-1) + tamanho >= COLUNAS - 1 && tamanho > 1) {
        return 0; // Saída dos limites
    }

    for (int i = x; i < x + tamanho; i++) {
        for (int j = y; j < y + tamanho; j++) {
            if (quadro[i][j] != ' ') {
                return 0; // Posição ocupada
            }
        }
    }
    return 1; // Posição livre
}


// Função principal para gerar a obra de arte
void gerar_arte(int tipo_figura, int num_figuras) {

    char quadro[LINHAS][COLUNAS];
    criar_quadro(quadro);


    if(tipo_figura == 5){
        gerar_arte_raposa(num_figuras,quadro);
        return;
    }


    for (int i = 0; i < num_figuras; i++) {
        int x, y;
        do {
            gerar_posicao_aleatoria(&x, &y);
        } while (posicao_livre(x, y, quadro, tipo_figura != 1 ? 3 : 1) == 0);

        // Desenha a figura de acordo com o tipo escolhido
        switch (tipo_figura) {
            case 1:
                asterisco_simples(x, y, quadro);
                break;
            case 2:
                simbolo_soma(x, y, quadro);
                break;
            case 3:
                letra_x(x, y, quadro);
                break;
            case 4: {
                int figura_aleatoria = rand() % 3 + 1; // Escolher uma figura aleatoriamente
                if (figura_aleatoria == 1)
                    asterisco_simples(x, y, quadro);
                else if (figura_aleatoria == 2)
                    simbolo_soma(x, y, quadro);
                else
                    letra_x(x, y, quadro);
                break;
            }
        }
    }

    imprimir_quadro(quadro);
}


void desenhar_raposa(char quadro[LINHAS][COLUNAS], int num_raposas) {
    int x, y;

    //int count=0;

    // Variável para verificar se a arte da raposa cabe na posição (x, y)
    int espaco_livre;
    int controle = 0;
    for(int i = 0; i < num_raposas; i++){
        // Verificar se a posição (x, y) está livre
        do{
            espaco_livre = 1; // Inicialmente assume que o espaço está livre e reseta a variável todo loop

            if(controle == num_raposas){   
                return;
            }

            // Gerar posições aleatórias para a raposa.
            y = rand() % (COLUNAS - 8) + 1; // Valor minimo sera 1 e maximo 72 
            x = rand() % (LINHAS - 5) + 1;   // Valor minimo sera 1 e maximo 15
            


            // Verifica os espaços onde a raposa será desenhada
            for (int dx = 0; dx < 4; dx++) { // Altura da raposa (4 linhas)
                for (int dy = 0; dy < 7; dy++) { // Largura da raposa (6 colunas)
                    if (quadro[x + dx][y + dy] != ' ') {
                        espaco_livre = 0; // Alguma parte já está ocupada
                        break;
                    }
                }
                if (espaco_livre == 0){
                    //count++;
                    //printf("Conflito de posicao, qtd conflitos: %d", count);
                    break; // Sai do loop se encontrar ocupação
                }
            }
            controle++;
            //printf("(controle): %d\n", controle);
            
        }while(espaco_livre == 0);
        


        if (x > 0 && y > 0) {
        //Desenha arte de raposa no quadro
        quadro[x + 0][y + 0] = ' '; 
        quadro[x + 0][y + 1] = '/'; 
        quadro[x + 0][y + 2] = '\\'; 
        quadro[x + 0][y + 3] = '_'; 
        quadro[x + 0][y + 4] = '/'; 
        quadro[x + 0][y + 5] = '\\';
        quadro[x + 1][y + 0] = ' '; 
        quadro[x + 1][y + 1] = '\\'; 
        quadro[x + 1][y + 2] = 'o'; 
        quadro[x + 1][y + 3] = ' '; 
        quadro[x + 1][y + 4] = 'o'; 
        quadro[x + 1][y + 5] = '/';
        quadro[x + 2][y + 0] = ' '; 
        quadro[x + 2][y + 1] = '/'; 
        quadro[x + 2][y + 2] = '\\'; 
        quadro[x + 2][y + 3] = '_'; 
        quadro[x + 2][y + 4] = '/'; 
        quadro[x + 2][y + 5] = '\\';
        quadro[x + 3][y + 0] = '/'; 
        quadro[x + 3][y + 1] = '|'; 
        quadro[x + 3][y + 2] = '|'; 
        quadro[x + 3][y + 3] = ' '; 
        quadro[x + 3][y + 4] = '|'; 
        quadro[x + 3][y + 5] = '|';
        quadro[x + 3][y + 6] = '\\';
        }
    }
}

void gerar_arte_raposa(int num_raposas, char quadro[LINHAS][COLUNAS]) {

    // Desenhar o raposa no quadro
    desenhar_raposa(quadro, num_raposas);

    // Imprimir o quadro final
    imprimir_quadro(quadro);

}

