#include <stdio.h>
#include <time.h>
#include "financas.h"

int main() {
    gerar_transacoes();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int mes_atual = tm.tm_mon + 1;
    int ano_atual = tm.tm_year + 1900;
    
    int opcao;
    int mes_escolhido, ano_escolhido;

    do {
        printf("\n");
        printf("%s==================================================\n", COR_NEGRITO);
        printf("       PAINEL DE ESCALA - MODULO DE CONTROLE\n");
        printf("==================================================%s\n", COR_RESET);
        printf("  1. Visualizar Painel do Mes Atual (%02d/%d)\n", mes_atual, ano_atual);
        printf("  2. Visualizar Painel de Outro Mes\n");
        printf("  3. Exportar Relatorio CSV (Mes Atual)\n");
        printf("  0. Sair\n");
        printf("==================================================\n");
        printf("  Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                exibir_dashboard(mes_atual, ano_atual);
                break;
            case 2:
                printf("\n  Informe o Mes (1-12): ");
                scanf("%d", &mes_escolhido);
                printf("  Informe o Ano (ex: 2026): ");
                scanf("%d", &ano_escolhido);
                exibir_dashboard(mes_escolhido, ano_escolhido);
                break;
            case 3:
                exportar_relatorio(mes_atual, ano_atual);
                break;
            case 0:
                printf("\n%sEncerrando sistema... Ate logo, Chefe!%s\n", COR_VERDE, COR_RESET);
                break;
            default:
                printf("\n%sOpcao invalida!%s\n", COR_VERMELHO, COR_RESET);
        }
    } while(opcao != 0);

    return 0;
}