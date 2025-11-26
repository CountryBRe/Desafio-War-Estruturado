# ⚔️ Desafio WAR Estruturado em C

Este repositório contém a implementação do jogo **WAR** em linguagem C, desenvolvida como atividade prática para o estudo de **estruturas de dados**, **ponteiros**, **alocação dinâmica de memória** e **modularização**.

O projeto simula uma versão simplificada do jogo WAR, com cadastro de territórios, sistema de batalhas e missões estratégicas.

---

## 🧩 Organização do Projeto

O sistema foi construído seguindo três níveis de dificuldade:

- **Nível Novato**
- **Nível Aventureiro**
- **Nível Mestre**

Cada nível representa a evolução do jogo, desde o cadastro básico dos territórios até a implementação completa de missões estratégicas e condição de vitória.

---

## ✅ NÍVEL NOVATO — Cadastro de Territórios

Neste nível foi criada a struct `Territorio` para armazenar os dados:

- Nome do território
- Cor do exército
- Quantidade de tropas

Os territórios são registrados em um vetor e exibidos na tela após o cadastro.

---

## ✅ NÍVEL AVENTUREIRO — Sistema de Ataque

Neste nível foi implementado o sistema de batalhas entre territórios.

### Funcionalidades:

- Uso de ponteiros para manipular os territórios
- Alocação dinâmica de memória com `malloc` e `calloc`
- Simulação de ataque utilizando `rand()`
- Atualização automática da cor e das tropas

### Regra de batalha:

- Se o atacante vencer, o território defensor muda de dono.
- Caso contrário, o atacante perde tropas.

---

## ✅ NÍVEL MESTRE — Missões Estratégicas

Foi adicionado o sistema de missões individuais.

Cada jogador recebe uma missão automática no início da partida, como por exemplo:

- Dominar territórios
- Eliminar uma cor específica
- Conquistar vários territórios

O sistema verifica ao final de cada rodada se a missão foi concluída e, em caso positivo, declara o vencedor.

---

## 🎨 Sistema de Cores ANSI no Terminal

O jogo utiliza cores no terminal para facilitar a visualização:

| Cor      | Significado        |
|-----------|------------------|
| 🟢 Verde  | Vitória / sucesso |
| 🔴 Vermelho | Derrota / erro   |
| 🟡 Amarelo | Dados da batalha |
| 🔵 Azul   | Mensagens do sistema |

---

## 📁 Arquivo Principal

Todo o projeto está implementado em um único arquivo.

✅ Compilação e Execução 

Compilar: Abra o terminal na pasta do projeto e execute:

gcc -Wall -Wextra -std=c99 War-Estruturado.c -o war
