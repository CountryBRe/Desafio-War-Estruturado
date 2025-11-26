# Desafio War Estruturado em C

Este repositório contém a implementação do jogo WAR em linguagem C, desenvolvida como atividade prática para o estudo de estruturas de dados, ponteiros, alocação dinâmica e modularização.

O projeto foi construído seguindo três níveis de dificuldade:
- Nível Novato
- Nível Aventureiro
- Nível Mestre

Cada nível representa a evolução do sistema, desde o cadastro básico de territórios até a implementação de missões estratégicas completas.

---

## ✅ NÍVEL NOVATO — Cadastro de Territórios

Foi criada a `struct Territorio` para armazenar:
- Nome do território
- Cor do exército
- Quantidade de tropas

Os territórios são registrados em um vetor e exibidos após o cadastro.

---

## ✅ NÍVEL AVENTUREIRO — Sistema de Ataque

Neste nível, foi implementado o sistema de batalhas entre territórios.

Funcionalidades:
- Uso de ponteiros para manipular os territórios
- Alocação dinâmica com `malloc`
- Simulação de ataque usando `rand()`
- Atualização automática da cor e das tropas

Regra de batalha:
- Se o atacante vencer, o território defensor muda de dono.
- Caso contrário, o atacante perde tropas.

---

## ✅ NÍVEL MESTRE — Missões Estratégicas

Foi adicionado o sistema de missões individuais por jogador.

Cada jogador recebe uma missão automática no início da partida, como:
- Dominar um continente
- Eliminar uma cor específica
- Conquistar múltiplos territórios

O sistema verifica ao final de cada rodada se alguém concluiu a missão.

---

## ✅ Compilação e Execução

### Compilar:
