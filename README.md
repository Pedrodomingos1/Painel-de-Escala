# 📊 Painel de Escala - Sistema Financeiro de Elite

![Status](https://img.shields.io/badge/Status-Concluído-success)
![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Autor](https://img.shields.io/badge/Autor-Pedro%20Domingos-orange)

> Um sistema de controle financeiro via terminal de alta performance, projetado para gestores que buscam clareza e eficiência.

---

## 🚀 Funcionalidades

O **Painel de Escala** oferece uma experiência visual robusta diretamente no seu terminal:

- **📈 Dashboard Visual:** Gráficos de barra ASCII que mostram a proporção de gastos por categoria.
- **🎨 Interface Cromática:** Indicadores de saúde financeira com cores dinâmicas (Verde/Vermelho) para facilitar a leitura.
- **📅 Filtro Temporal Inteligente:** Alterne instantaneamente entre a visão do mês atual e o histórico completo.
- **📂 Exportação Profissional:** Gere relatórios detalhados em CSV (`relatorio_financeiro.csv`) com um único comando.
- **💾 Persistência de Dados:** Banco de dados binário otimizado (`financas.dat`) para máxima velocidade.

---

## 🛠️ Como Executar

Este projeto foi desenvolvido em **C puro**. Siga os passos abaixo para compilar e rodar:

### Pré-requisitos
- Compilador GCC instalado.

### Compilação
```bash
gcc -o painel_escala principal.c dashboard.c gerador.c
Execução
./painel_escala
# ou no Windows:
.\painel_escala.exe
📸 Demonstração Visual
Ao iniciar o sistema, você verá o Menu de Controle:

==================================================
       PAINEL DE ESCALA - MODULO DE CONTROLE
==================================================
  1. Visualizar Painel do Mes Atual
  2. Visualizar Painel de Outro Mes
  3. Exportar Relatorio CSV
  0. Sair
==================================================
O Painel Financeiro exibe os dados com clareza:

==================================================
   PAINEL FINANCEIRO DE ELITE - 02/2026
==================================================

  [+] Entradas:       R$ 4000.50
  [-] Saidas:         R$ 1320.00
  --------------------------------------------------
  [=] Saldo Final:    R$ 2680.50

--- Distribuicao de Gastos (Top Categorias) ---
  Aluguel          [##################------------] 60.6%
  Energia          [####--------------------------] 15.2%
  Mercado          [##----------------------------] 9.1%
📂 Estrutura do Projeto
Arquivo	Descrição
principal.c	Núcleo do sistema e menu interativo.
dashboard.c	Lógica de visualização, cálculos e gráficos ASCII.
gerador.c	Módulo responsável por popular o banco de dados inicial.
financas.h	Cabeçalho com definições de estruturas e constantes.
financas.dat	Arquivo binário onde os dados são persistidos.
