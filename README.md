# Exame Final CTC-34

- Arthur Costa Stevenson Mota
- Eduardo de Moura Simplício
- Matheus Silva Ramos

O Exame Final da disciplina CTC-34 consiste em realizar a implementação de um *auto-complete* usando diferentes algoritmos, e então realizar comparações entre eles. Nesse caso, foram feitas as duas implementações obrigatórias, sendo elas um Autômato de Levenshtein, e um Transdutor de Estado Finito e, para a implementação opcional, foi escolhida a Árvore Rubro-Negra.
A seguir, estão os testes realizados para comparar os três diferentes algoritmos em diferentes contextos.

## Análise do Dicionário Usado

Para o estudo da eficiência do *auto-complete*, foi utilizado o dicionário disponibilizado juntamente ao Linux, para o Inglês Americano. Na Figura 1, pode-se observar a distribuição das palavras no dicionário, de acordo com as suas primeiras letras.

| ![dictdist](./src/Analysis/dict_dist.png) |
|-|
|Figura 2: Distribuição de palavras no dicionário de acordo com as suas letras iniciais. Nota-se que as cinco letras com mais entradas, em ordem decrescente, são 'S', 'C', 'P', 'B' e 'M'.|

## Criação dos Dicionários

Antes de serem realizados quaiser testes quanto à velocidade de execução do algoritmo de *auto-complete*, os três diferentes algoritmos precisam completar uma etapa de preparação. No caso do Autômato de Levenshtein, isso significa importar as palavras do dicionário para uma lista que será percorrida, para a Árvore RB e o FST, criar as suas estruturas típicas, com base no dicionário de palavras especificado.

Assim, os tempos de preparação de cada um dos algoritmos estão apresentados no gráfico da Figura 1. Analisando-se os resultados apresentados na figura, nota-se que o tempo de preparação do Autômato de Levenshtein é significativamente menor que os demais, o que se deve ao fato de esta etapa, para esse algoritmo, ser constituída simplesmente pela adição das *strings* do dicionário, sem que computações adicionais sejam feitas.

| ![preptime](./src/Analysis/dict_creation.png) |
|-|
|Figura 2: Tempos de preparação dos três métodos estudados.|

## Testes com Caractere Único

Para uma comparação inicial, foram feitos testes de *auto-complete* utilizando-se apenas um caractere. Os gráficos abaixo apresentam o tempo de execução dos três algoritmos implementados, Levenshtein considerando distância 1, Árvore Rubro-Negra, e FST.

|![levenstr](./src/Analysis/leven_char.png)|
| :-: |
|Figura 3: Tempos de execução para cada letra do alfabeto do autômato de Levenshtein com distância 1.|

|![rbstr](./src/Analysis/rb_char.png)|
| :-: |
|Figura 4: Tempos de execução para cada letra do alfabeto da árvore rubro-negra.|

|![fststr](./src/Analysis/rb_char.png)|
| :-: |
|Figura 5: Tempos de execução para cada letra do alfabeto do FST.|

