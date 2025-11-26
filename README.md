# ⚔️ Desafio WAR Estruturado em C

Este repositório contém a implementação do jogo **WAR** em linguagem C, desenvolvida como atividade prática para o estudo de **estruturas de dados**, **ponteiros**, **alocação dinâmica de memória** e **modularização**.

O projeto simula uma versão simplificada do jogo WAR, permitindo cadastro de territórios, batalhas estratégicas e sistema de missões.

---

## 🧩 Organização do Projeto

O desenvolvimento foi dividido em três níveis de dificuldade:

### 🔹 Nível Novato
Cadastro básico dos territórios usando `struct`.

### 🔹 Nível Aventureiro
Implementação do sistema de ataque entre territórios com ponteiros e alocação dinâmica.

### 🔹 Nível Mestre
Sistema de missões estratégicas e condição automática de vitória.

---

## ✅ NÍVEL NOVATO — Cadastro de Territórios

Foi criada a struct `Territorio` para armazenar:

- Nome do território  
- Cor do exército  
- Quantidade de tropas  

Os territórios são armazenados em um vetor e exibidos após o cadastro.

---

## ✅ NÍVEL AVENTUREIRO — Sistema de Ataque

Neste nível foi implementado o combate entre territórios.

### Funcionalidades:

- Uso de ponteiros para manipular os territórios
- Alocação dinâmica com `malloc` e `calloc`
- Simulação de ataque com `rand()`
- Atualização automática da cor e das tropas

### Regra de batalha:

- Se o atacante vencer, o território defensor muda de dono.
- Caso contrário, o atacante perde tropas.

---

## ✅ NÍVEL MESTRE — Missões Estratégicas

Foi adicionado um sistema de missões individuais por jogador.

Exemplos de missões:

- Dominar territórios específicos
- Eliminar uma cor inimiga
- Conquistar diversos territórios

O sistema verifica automaticamente após cada rodada se a missão foi cumprida.

---

## 🎨 Sistema de Cores ANSI

O jogo utiliza cores para melhorar a visualização no terminal:

| Cor      | Significado         |
|----------|-------------------|
| 🟢 Verde  | Vitória / sucesso |
| 🔴 Vermelho | Derrota / erro   |
| 🟡 Amarelo | Dados da batalha |
| 🔵 Azul   | Mensagens do sistema |

---

👨‍💻 Autor: Rodrigo Gomes
📘 Disciplina: Introdução à Programação de Computadores
🏫 Faculdade: Estácio de Sá
👨‍🏫 Professor: Sérgio Cardoso

## ⚙️ Compilação e Execução

### Compilar

Execute no terminal dentro da pasta do projeto:

```bash
gcc -Wall -Wextra -std=c99 War-Estruturado.c -o war


