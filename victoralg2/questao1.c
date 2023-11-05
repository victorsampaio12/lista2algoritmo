#include <stdio.h>

int main() {
  // Declaração de variáveis
  int entrada[10], saida[10];
  int i, j, k;

  // Leitura da entrada
  for (i = 0; i < 10; i++) {
    scanf("%d", &entrada[i]);
  }

  // Impressão da entrada
  printf("Entrada: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", entrada[i]);
  }
  printf("\n");

  // Processamento
  for (i = 0; i < 10; i++) {
    // Cálculo do novo elemento da janela deslizante
    saida[i] = entrada[i] + entrada[i + 1];

    // Deslocamento da janela
    for (j = i; j < 9; j++) {
      entrada[j] = entrada[j + 1];
    }

    // Impressão do novo conjunto
    printf("Saída: ");
    for (k = 0; k <= i; k++) {
      printf("%d ", saida[k]);
    }
    printf("\n");
  }

  return 0;
}