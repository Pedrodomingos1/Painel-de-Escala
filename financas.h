#ifndef FINANCAS_H
#define FINANCAS_H

#define MAX_CAT 20

#define COR_RESET   "\x1b[0m"
#define COR_VERMELHO "\x1b[31m"
#define COR_VERDE   "\x1b[32m"
#define COR_AMARELO "\x1b[33m"
#define COR_CIANO    "\x1b[36m"
#define COR_NEGRITO  "\x1b[1m"

typedef struct {
    int id;
    int tipo;
    double valor;
    int dia;
    int mes;
    int ano;
    char categoria[MAX_CAT];
} Transacao;

void gerar_transacoes();
void exibir_dashboard(int mes, int ano);
void exportar_relatorio(int mes, int ano);

#endif