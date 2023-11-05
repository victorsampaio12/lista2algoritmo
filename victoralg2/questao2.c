#include <stdio.h>

// Estrutura para representar um jogador
struct jogador {
  char nome[30];
  char posicao;
  int forca;
};

// Função para calcular a força ponderada de um time
float calcularForca(struct jogador *jogadores, int n) {
  float forca = 0;
  int i;

  // Calcula a força do goleiro
  forca += 8 * jogadores[0].forca;

  // Calcula a força dos laterais
  forca += 10 * (jogadores[1].forca + jogadores[2].forca);

  // Calcula a força dos zagueiros
  forca += 5 * (jogadores[3].forca + jogadores[4].forca);

  // Calcula a força dos volantes
  forca += 8 * (jogadores[5].forca + jogadores[6].forca);

  // Calcula a força dos meias
  forca += 11 * (jogadores[7].forca + jogadores[8].forca);

  // Calcula a força dos atacantes
  forca += 12 * (jogadores[9].forca + jogadores[10].forca);

  return forca;
}

// Função principal
int main() {
  // Declaração de variáveis
  struct jogador time1[12], time2[12];
  char nomeTime1[30], nomeTime2[30];
  int i;

  // Lê o nome do primeiro time
  printf("Nome do primeiro time: ");
  scanf("%s", nomeTime1);

  // Lê os jogadores do primeiro time
  for (i = 0; i < 12; i++) {
    printf("Nome do jogador %d: ", i + 1);
    scanf("%s;%c;%d", time1[i].nome, &time1[i].posicao, &time1[i].forca);
  }

  // Lê o nome do segundo time
  printf("Nome do segundo time: ");
  scanf("%s", nomeTime2);

  // Lê os jogadores do segundo time
  for (i = 0; i < 12; i++) {
    printf("Nome do jogador %d: ", i + 1);
    scanf("%s;%c;%d", time2[i].nome, &time2[i].posicao, &time2[i].forca);
  }

  // Verifica se o número de jogadores de cada time é válido
  if (n != 12) {
    printf("Erro: número de jogadores inválido.\n");
    exit(1);
  }

  // Calcula a força ponderada do primeiro time
  float forcaTime1 = calcularForca(time1, 12);

  // Calcula a força ponderada do segundo time
  float forcaTime2 = calcularForca(time2, 12);

  // Imprime a força ponderada de cada time
  printf("Força do %s: %.2f\n", nomeTime1, forcaTime1);
  printf("Força do %s: %.2f\n", nomeTime2, forcaTime2);

  // Determina o time mais forte
  if (forcaTime1 > forcaTime2) {
    printf("%s é o mais forte.\n", nomeTime1);
  } else {
    printf("%s é o mais forte.\n", nomeTime2);
  }

  return 0;
}