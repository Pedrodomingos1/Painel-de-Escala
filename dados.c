#include <stdio.h>
#include <string.h>
#include <time.h>
#include "financas.h"

#define ARQUIVO_DADOS "financas.dat"
#define ARQUIVO_BACKUP "financas.bak"

int inicializar_banco_dados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");
    
    if (arquivo == NULL) {
        criar_arquivo_inicial();
        return 1;
    }
    
    fclose(arquivo);
    return 1;
}

void criar_arquivo_inicial() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de dados financeiros.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int mes_atual = tm.tm_mon + 1;
    int ano_atual = tm.tm_year + 1900;
    int mes_anterior = (mes_atual == 1 ? 12 : mes_atual - 1);
    int ano_anterior = (mes_atual == 1 ? ano_atual - 1 : ano_atual);

    Transacao transacoes[] = {
        {1, 1, 3500.50, 1, mes_atual, ano_atual, "Salario"},
        {2, 0, 800.00, 5, mes_atual, ano_atual, "Aluguel"},
        {3, 0, 200.00, 10, mes_atual, ano_atual, "Energia"},
        {4, 0, 50.00, 15, mes_atual, ano_atual, "Internet"},
        {5, 0, 120.00, 20, mes_atual, ano_atual, "Mercado"},
        {6, 1, 500.00, 25, mes_atual, ano_atual, "Bonus"},
        {7, 0, 150.00, 28, mes_atual, ano_atual, "Lazer"},
        
        {8, 1, 3000.00, 1, mes_anterior, ano_anterior, "Salario"},
        {9, 0, 800.00, 5, mes_anterior, ano_anterior, "Aluguel"},
        {10, 0, 300.00, 15, mes_anterior, ano_anterior, "Mercado"},
        {11, 0, 100.00, 20, mes_anterior, ano_anterior, "Lazer"},
        {12, 1, 200.00, 25, mes_anterior, ano_anterior, "Venda"}
    };

    size_t tamanho = sizeof(transacoes) / sizeof(Transacao);
    fwrite(transacoes, sizeof(Transacao), tamanho, arquivo);

    fclose(arquivo);
}

void criar_backup_automatico() {
    FILE *origem = fopen(ARQUIVO_DADOS, "rb");
    FILE *destino = fopen(ARQUIVO_BACKUP, "wb");
    
    if (origem && destino) {
        char buffer[256];
        size_t bytes;
        while((bytes = fread(buffer, 1, sizeof(buffer), origem)) > 0) {
            fwrite(buffer, 1, bytes, destino);
        }
    }
    
    if(origem) fclose(origem);
    if(destino) fclose(destino);
}
