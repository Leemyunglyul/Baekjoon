# [Platinum III] SUMO - 9666 

[문제 링크](https://www.acmicpc.net/problem/9666) 

### 성능 요약

메모리: 9252 KB, 시간: 76 ms

### 분류

이분 그래프, 자료 구조, 분리 집합, 그래프 이론

### 제출 일자

2024년 10월 8일 23:48:44

### 문제 설명

<p>In a Japanese monastery, otherwise known for serious fasting and ascetic life, the Head of the sumo wrestling section has decided to organise training-competitions for his N fighters. He determined the exact sequence of M fights and its participants (two fighters face each other per fight). </p>

<p>Just moments before the competition, the Head realised he could easily stir things up a bit! He could divide his fighters into two teams so that only fighters of different teams face each other in each fight. Since the fighting schedule has already been made and it doesn't meet this condition, and we mustn't change it for whatever zen reason there is, the Head is left with only one option. That is to divide the fighters into two teams so that the fighters from the same team face each other in a fight as late as possible. </p>

<p>Help the Head! For a given fighting schedule, determine the ordinal number of the first fight where two fighters from the same team have to face each other, under the condition that we divide them in the best possible way, so that the required fight takes place as late as possible. In all test data, such fight will definitely occur. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100 000), the number of fighters. The fighters are marked with numbers from 1 to N. </p>

<p>The second line of input contains the integer M (1 ≤ M ≤ 300 000), the number of fights. </p>

<p>Each of the following M lines contains fights in the order which they must take place. Each line contains two different integers from the interval [1, N]: the labels of fighters who are going to face each other. </p>

### 출력 

 <p>The first and only line of output must contain the ordinal number (from 1 to M) of the required fight.</p>

