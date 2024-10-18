#include "figuras.h"

// Menu principal
void menu() {
    int tipo_figura, num_figuras;

    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples.\n");
    printf("2 - simbolo de soma com asteriscos.\n");
    printf("3 - letra X com asteriscos.\n");
    printf("4 - figuras aleatorias.\n");
    printf("5 - obra de arte de raposa\n");

    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &tipo_figura);

    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d", &num_figuras);

    if (num_figuras <= 0) {
        num_figuras = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    } else if (num_figuras > 100) {
        num_figuras = 100;
    }

    
    if (tipo_figura == 5) {

        if (num_figuras <= 0) {
            num_figuras = rand() % 50 + 1; // Gera um número aleatório entre 1 e 50
        } else if (num_figuras > 50) {
            num_figuras = 50; // Limita a 50 figuras
        }

    }

    gerar_arte(tipo_figura, num_figuras);

}

// Função principal
int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    menu();
    return 0;
}
