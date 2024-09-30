# [Platinum III] Homem, Elefante e Rato - 13656 

[문제 링크](https://www.acmicpc.net/problem/13656) 

### 성능 요약

메모리: 8272 KB, 시간: 1204 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 9월 30일 12:01:46

### 문제 설명

<p>Um jogo muito popular na Nlogônia é o Homem, Elefante e Rato. Ele é tipicamente jogado com apenas dois jogadores, e funciona da seguinte forma: cada jogador secretamente escolhe um dos três símbolos e, após uma contagem regressiva, ambos revelam simultaneamente o símbolo escolhido através de sinais manuais, estendendo à sua frente uma das mãos sinalizando sua escolha.</p>

<p>O Homem é representado pela mão fechada, como a cabeça de um homem. O Elefante é representado pela mão aberta, exibindo os cinco dedos, como a pata do elefante nlogonense. Por fim, o Rato é representado pela mão fechada, com o dedo indicador e o dedo médio esticados, como as orelhas do pequeno animal.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13656/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-12%20%EC%98%A4%EC%A0%84%206.12.11.png" style="height:103px; width:279px"><br>
 </p>

<p>Figura 1: Os três símbolos do jogo Homem, Elefante e Rato.</p>

<p>Para determinar o vencedor é muito simples: o Homem sempre perde para o Elefante (pois é esmagado debaixo de sua pata), o Elefante sempre perde para o Rato (pois tem medo dele e foge correndo) e o Rato sempre perde para o Homem (que espalha ratoeiras para capturá-lo). Se dois jogadores utilizarem o mesmo símbolo, ocorre um empate e joga-se novamente.</p>

<p>Os habitantes da Nlogônia, que são estrategistas natos de Homem, Elefante e Rato, utilizam a seguinte técnica no campeonato nacional, realizado todos os anos: começam sempre jogando Homem até o momento em que este símbolo causa empates com a maioria dos oponentes. Eles então trocam sua estratégia para o símbolo que ganha daquele que usavam anteriormente. Assim, os jogadores vão mudar de Homem para Elefante, depois para Rato, depois de volta a Homem.</p>

<p>Para auxiliar um famoso competidor estrangeiro de um jogo com uma certa similaridade com este jogo de Homem, Elefante e Rato, você irá desenvolver um programa que contabiliza quantos jogadores irão utilizar cada símbolo.</p>

<p>Suponha que todos os N jogadores são dispostos em fila e identificados pela sua posição, de 1 a N. Seu programa deverá processar M comandos, de dois tipos: mudança de símbolo e contar a frequência dos símbolos. Ambos os comandos recebem um intervalo contíguo de jogadores na fila a serem considerados.</p>

### 입력 

 <p>A entrada é composta por diversos casos de teste. Cada caso de teste começa com uma linha contendo dois inteiros N (1 ≤ N ≤ 10<sup>5</sup>) ​​e M (0 ≤ M ≤ 10<sup>6</sup>) ​que representam, respectivamente, o número de jogadores no campeonato e o número de operações.</p>

<p>As próximas M linhas contêm cada uma a descrição de uma operação. Operações de mudança de estratégia serão representadas por uma linha da forma "M A B" onde A (1 ≤ A) e B (A ≤ B ≤ N) são inteiros. Os jogadores cuja estratégias serão alteradas são aqueles cuja posição na fila está entre A e B, inclusive.</p>

<p>Operações de contagem serão representadas por uma linha da forma "C A B" onde A e B são inteiros representando o intervalo de jogadores que deverão ser considerados na contagem. Levaremos em conta os jogadores cuja posição na fila está entre A e B, inclusive.</p>

### 출력 

 <p>Para cada operação de contagem, imprima uma linha contendo três inteiros indicando respectivamente o número de símbolos Homem, Elefante e Rato que são usados pelos jogadores no intervalo dado.</p>

<p>Imprima também uma linha em branco após cada caso de teste, inclusive após o último caso de teste da entrada.</p>

