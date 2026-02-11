# 📊 Painel de Escala - Sistema Financeiro de Elite

![Status](https://img.shields.io/badge/Status-Concluído-success)
![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Interface](https://img.shields.io/badge/Interface-Python%20GUI-yellow)
![Autor](https://img.shields.io/badge/Autor-Pedro%20Domingos-orange)

> Um sistema de controle financeiro híbrido de alta performance: Backend robusto em C e Frontend moderno em Python.

---

## 🚀 Funcionalidades

O **Painel de Escala** oferece duas experiências de uso integradas:

### 🖥️ Módulo Terminal (C)
- **Dashboard ASCII:** Gráficos de barra via terminal para análise rápida.
- **Performance Extrema:** Processamento de dados binários em tempo real.
- **Exportação CSV:** Geração de relatórios compatíveis com Excel/Google Sheets.

### 🎨 Módulo Gráfico (Python)
- **Interface Dark Mode:** Visual moderno e confortável com *CustomTkinter*.
- **Dashboard Interativo:** Cards de resumo (Entradas, Saídas, Saldo) e barras de progresso visuais.
- **Sincronização Automática:** Lê diretamente os dados binários gerados pelo backend em C.

---

## 🛠️ Como Executar

### 1. Backend (Gerar Dados)
Primeiro, compile e execute o núcleo em C para gerar a base de dados (`financas.dat`).

```bash
# Compilar
gcc -o painel_escala principal.c dashboard.c gerador.c

# Executar (Windows)
.\painel_escala.exe
2. Frontend (Interface Gráfica)
Certifique-se de ter o Python instalado e as dependências:

# Instalar bibliotecas
pip install customtkinter pillow

# Iniciar a Interface
python interface.py
📂 Estrutura do Projeto
Arquivo	Descrição
principal.c	Núcleo do sistema e menu CLI.
dashboard.c	Lógica de visualização terminal.
gerador.c	Motor de geração de dados binários.
interface.py	Nova Interface Gráfica em Python.
financas.dat	Banco de dados binário compartilhado entre C e Python.
