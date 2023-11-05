#include <stdio.h>


// Função para ler uma matriz de inteiros
void lerMatriz(int matriz[][4], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
}

// Função para imprimir uma matriz de inteiros
void imprimirMatriz(int matriz[][4], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%*d", 4, matriz[i][j]);
    }
    printf("\n");
  }
}

// Função para somar duas matrizes
int **somarMatriz(int matrizA[][4], int matrizB[][4], int n) {
  int **matrizC = malloc(n * sizeof(int *));
  int i, j;

  for (i = 0; i < n; i++) {
    matrizC[i] = malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }

  return matrizC;
}

// Função para subtrair duas matrizes
int **subtrairMatriz(int matrizA[][4], int matrizB[][4], int n) {
  int **matrizC = malloc(n * sizeof(int *));
  int i, j;

  for (i = 0; i < n; i++) {
    matrizC[i] = malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      matrizC[i][j] = matrizA[i][j] - matrizB[i][j];
    }
  }

  return matrizC;
}

// Função para multiplicar duas matrizes
int **multiplicarMatriz(int matrizA[][4], int matrizB[][4], int n) {
  int **matrizC = malloc(n * sizeof(int *));
  int i, j, k;

  for (i = 0; i < n; i++) {
    matrizC[i] = malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      matrizC[i][j] = 0;
      for (k = 0; k < n; k++) {
        matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }

  return matrizC;
}

int main() {
  // Declaração de variáveis
  int matrizA[4][4], matrizB[4][4], matrizC[4][4];
  char operacao[10];
  int i, j;

  // Leitura das matrizes
  lerMatriz(matrizA, 4);
  lerMatriz(matrizB, 4);

  // Leitura da operação
  scanf("%s", operacao);

  // Execução da operação
  if (strcmp(operacao, "soma") == 0) {
    matrizC = somarMatriz(matrizA, matrizB, 4);
  } else if (strcmp(operacao, "sub") == 0) {
    matrizC = subtrairMatriz(matrizA, matrizB, 4);
  } else if (strcmp(operacao, "mult") == 0) {
    matrizC = multiplicarMatriz(matrizA, matrizB, 4);
  } else {
    printf("Operação inválida.\n");
    return 1;
  }

  // Impressão da matriz resultante
  imprimirMatriz(matrizC, 4);

  return 0;
}