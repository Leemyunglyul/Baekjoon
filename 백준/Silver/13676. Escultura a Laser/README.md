# [Silver IV] Escultura a Laser - 13676 

[문제 링크](https://www.acmicpc.net/problem/13676) 

### 성능 요약

메모리: 2152 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘, 자료 구조, 스택

### 제출 일자

2024년 2월 14일 16:49:33

### 문제 설명

<p>Desde a sua invenção, em 1958, os raios laser têm sido utilizados em uma imensa variedade de aplicações, como equipamentos eletrônicos, instrumentos cirúrgicos, armamentos, e muito mais.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13676/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-12%20%EC%98%A4%EC%A0%84%206.51.55.png" style="height:200px; width:310px"></p>

<p>A figura acima mostra um diagrama esquemático de um equipamento para esculpir, com laser, um bloco de material maciço. Na figura vemos um emissor laser que se desloca horizontalmente para a direita e para a esquerda com velocidade constante. Quando o emissor é ligado durante o deslocamento, uma camada de espessura constante é removida do bloco, sendo vaporizada pelo laser.</p>

<p>A figura abaixo ilustra o processo de escultura a laser, mostrando um exemplo de (a) um bloco, com 5 mm de altura por 8 mm de comprimento, no início do processo, (b) o formato que se deseja que o bloco esculpido tenha, e (c) a sequência de remoção das camadas do bloco durante o processo, considerando que a cada varredura uma camada de espessura de 1 mm é removida. Na primeira varredura, o pedaço numerado como 1 é removido; na segunda varredura, o pedaço numerado como 2 é removido, e assim por diante. Durante o processo de remoção, o laser foi ligado um total de 7 vezes, uma vez para cada pedaço de bloco removido.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13676/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-12%20%EC%98%A4%EC%A0%84%206.52.54.png" style="height:163px; width:617px"></p>

<p>Escreva um programa que, dados a altura do bloco, o comprimento do bloco, e a forma final que o bloco deve ter, determine o número total vezes de que o laser deve ser ligado para esculpir o bloco.</p>

### 입력 

 <p>A entrada contém vários casos de teste. Cada caso de teste é composto por duas linhas. A primeira linha de um caso de teste contém dois números inteiros A e C, separados por um espaço em branco, indicando respectivamente a altura (1 ≤ A ≤ 10<sup>4</sup>) e o comprimento (1 ≤ C ≤ 10<sup>4</sup>) do bloco a ser esculpido, em milímetros. A segunda linha contém C números inteiros Xi, cada um indicando a altura final, em milímetros, do bloco entre as posições i e i + 1 ao longo do comprimento (0 ≤ X<sub>i</sub> ≤ A, para 0 ≤ i ≤ C - 1). Considere que a cada varredura uma camada de espessura 1 milímetro é removida do bloco ao longo dos pontos onde o laser está ligado.</p>

<p>O final da entrada é indicado por uma linha que contém apenas dois zeros, separados por um espaço em branco.</p>

### 출력 

 <p>Para cada caso de teste da entrada seu programa deve imprimir uma única linha, contendo um número inteiro, indicando o número de vezes que o laser deve ser ligado para esculpir o bloco na forma indicada.</p>

