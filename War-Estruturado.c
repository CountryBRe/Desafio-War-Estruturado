#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ======================
// SISTEMA DE CORES
// ======================
#define VERDE   "\033[1;32m"
#define VERMELHO "\033[1;31m"
#define AMARELO "\033[1;33m"
#define AZUL    "\033[1;34m"
#define RESET   "\033[0m"

// ======================
// STRUCT DO TERRITÓRIO
// ======================
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ======================
// FUNÇÕES
// ======================
void cadastrarTerritorios(Territorio *mapa, int total);
void exibirMapa(Territorio *mapa, int total);
void atacar(Territorio *atacante, Territorio *defensor);
void liberarMemoria(Territorio *mapa, char *missao);
void atribuirMissao(char *destino, char *missoes[], int totalMissoes);
int verificarMissao(char *missao, Territorio *mapa, int total);

// ======================
// CADASTRO DOS TERRITÓRIOS
// ======================
void cadastrarTerritorios(Territorio *mapa, int total) {
    for (int i = 0; i < total; i++) {
        printf("\nCadastro do território %d\n", i + 1);

        printf("Nome: ");
        scanf(" %29[^\n]", mapa[i].nome);

        printf("Cor do exército: ");
        scanf(" %9s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// ======================
// EXIBIÇÃO DO MAPA
// ======================
void exibirMapa(Territorio *mapa, int total) {
    printf("\n================ MAPA =================\n");
    for (int i = 0; i < total; i++) {
        printf("%d - %s | Cor: %s | Tropas: %d\n",
               i,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }
    printf("======================================\n");
}

// ======================
// FUNÇÃO DE ATAQUE
// ======================
void atacar(Territorio *atacante, Territorio *defensor) {

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf(AMARELO "\nDado atacante: %d | Dado defensor: %d\n" RESET, dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf(VERDE "Vitória no ataque!\n" RESET);

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = defensor->tropas / 2;
        if (defensor->tropas < 1)
            defensor->tropas = 1;

    } else {
        printf(VERMELHO "Derrota no ataque!\n" RESET);
        atacante->tropas--;

        if (atacante->tropas < 1) {
            atacante->tropas = 1;
        }
    }
}

// ======================
// SORTEIO DE MISSÃO
// ======================
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// ======================
// VERIFICA MISSÃO
// ======================
int verificarMissao(char *missao, Territorio *mapa, int total) {

    int contador = 0;

    for (int i = 0; i < total; i++) {
        if (strcmp(mapa[i].cor, "Azul") == 0) {
            contador++;
        }
    }

    if (strcmp(missao, "Conquistar 3 territorios Azuis") == 0 && contador >= 3) {
        printf(VERDE "\nMissão cumprida!\n" RESET);
        return 1;
    }

    return 0;
}

// ======================
// LIBERA MEMÓRIA
// ======================
void liberarMemoria(Territorio *mapa, char *missao) {
    free(mapa);
    free(missao);
}

// ======================
// MAIN
// ======================
int main() {
    srand(time(NULL));

    int total;
    printf("Quantidade de territórios: ");
    scanf("%d", &total);

    // Alocação dinâmica
    Territorio *mapa = calloc(total, sizeof(Territorio));
    char *missao = malloc(100 * sizeof(char));

    cadastrarTerritorios(mapa, total);

    // Vetor de missões
    char *missoes[] = {
        "Conquistar 3 territorios Azuis",
        "Dominar metade do mapa",
        "Eliminar uma cor inimiga",
        "Chegar a 10 tropas",
        "Conquistar dois territórios seguidos"
    };

    atribuirMissao(missao, missoes, 5);

    printf(AZUL "\nSua missão é: %s\n" RESET, missao);

    int continuar = 1;

    while (continuar) {
        int a, d;

        exibirMapa(mapa, total);

        printf("\nEscolha o território atacante: ");
        scanf("%d", &a);

        printf("Escolha o território defensor: ");
        scanf("%d", &d);

        if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
            printf(VERMELHO "\nVocê não pode atacar seu próprio território!\n" RESET);
            continue;
        }

        atacar(&mapa[a], &mapa[d]);

        if (verificarMissao(missao, mapa, total)) {
            printf(VERDE "\nVITÓRIA! MISSÃO CONCLUÍDA!\n" RESET);
            break;
        }

        printf("\nContinuar jogando? (1 = sim / 0 = não): ");
        scanf("%d", &continuar);
    }

    liberarMemoria(mapa, missao);

    printf(AZUL "\nFim do jogo.\n" RESET);

    return 0;
}