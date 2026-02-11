#include <stdio.h>
#include <string.h>
#include "financas.h"

#define BARRA_MAXIMA 30

void desenhar_barra_progresso(double percentual, char *cor) {
    int preenchido = (int)((percentual / 100.0) * BARRA_MAXIMA);
    printf("%s[", cor);
    for (int i = 0; i < BARRA_MAXIMA; i++) {
        if (i < preenchido) printf("#");
        else printf("-");
    }
    printf("] %.1f%%%s\n", percentual, COR_RESET);
}

void exibir_dashboard(int mes, int ano) {
    FILE *arquivo = fopen("financas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir base de dados.\n");
        return;
    }

    double total_entradas = 0.0;
    double total_saidas = 0.0;
    
    char categorias[MAX_CAT][MAX_CAT];
    double valores_por_categoria[MAX_CAT] = {0};
    int quantidade_categorias = 0;

    Transacao transacao;
    while(fread(&transacao, sizeof(Transacao), 1, arquivo)) {
        if (transacao.mes == mes && transacao.ano == ano) {
            if (transacao.tipo == 1) {
                total_entradas += transacao.valor;
            } else {
                total_saidas += transacao.valor;
                
                int encontrou = 0;
                for(int i=0; i < quantidade_categorias; i++) {
                    if(strcmp(categorias[i], transacao.categoria) == 0) {
                        valores_por_categoria[i] += transacao.valor;
                        encontrou = 1;
                        break;
                    }
                }
                if(!encontrou && quantidade_categorias < MAX_CAT) {
                    strcpy(categorias[quantidade_categorias], transacao.categoria);
                    valores_por_categoria[quantidade_categorias] = transacao.valor;
                    quantidade_categorias++;
                }
            }
        }
    }

    fclose(arquivo);

    double saldo_final = total_entradas - total_saidas;
    char *cor_saldo = saldo_final >= 0 ? COR_VERDE : COR_VERMELHO;

    printf("\n");
    printf("%s==================================================\n", COR_NEGRITO);
    printf("   PAINEL FINANCEIRO DE ELITE - %02d/%d\n", mes, ano);
    printf("==================================================%s\n\n", COR_RESET);
    
    printf("  %s[+] Entradas:%s       R$ %.2f\n", COR_VERDE, COR_RESET, total_entradas);
    printf("  %s[-] Saidas:%s         R$ %.2f\n", COR_VERMELHO, COR_RESET, total_saidas);
    printf("  --------------------------------------------------\n");
    printf("  %s[=] Saldo Final:%s    %sR$ %.2f%s\n\n", COR_CIANO, COR_RESET, cor_saldo, saldo_final, COR_RESET);

    printf("%s--- Distribuicao de Gastos (Top Categorias) ---%s\n", COR_AMARELO, COR_RESET);
    
    if (total_saidas > 0) {
        for(int i=0; i < quantidade_categorias; i++) {
            double percentual = (valores_por_categoria[i] / total_saidas) * 100.0;
            printf("  %-15s ", categorias[i]);
            desenhar_barra_progresso(percentual, COR_CIANO);
        }
    } else {
        printf("  Nenhum gasto registrado neste periodo.\n");
    }
    
    printf("\n%s==================================================%s\n", COR_NEGRITO, COR_RESET);
}

void exportar_relatorio(int mes, int ano) {
    FILE *entrada = fopen("financas.dat", "rb");
    if (!entrada) return;

    FILE *saida = fopen("relatorio_financeiro.csv", "w");
    if (!saida) {
        fclose(entrada);
        printf("Erro ao criar relatorio_financeiro.csv\n");
        return;
    }

    fprintf(saida, "ID,Data,Tipo,Categoria,Valor\n");

    Transacao transacao;
    while(fread(&transacao, sizeof(Transacao), 1, entrada)) {
        if (transacao.mes == mes && transacao.ano == ano) {
            fprintf(saida, "%d,%02d/%02d/%d,%s,%s,%.2f\n",
                transacao.id, transacao.dia, transacao.mes, transacao.ano,
                transacao.tipo == 1 ? "Entrada" : "Saida",
                transacao.categoria, transacao.valor);
        }
    }

    fclose(entrada);
    fclose(saida);
    printf("\n%sArquivo 'relatorio_financeiro.csv' exportado com sucesso!%s\n", COR_VERDE, COR_RESET);
}