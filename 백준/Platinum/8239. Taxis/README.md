# [Platinum III] Taxis - 8239 

[문제 링크](https://www.acmicpc.net/problem/8239) 

### 성능 요약

메모리: 8292 KB, 시간: 168 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 4월 4일 19:24:24

### 문제 설명

<p>Byteasar wants to take a taxi from the town Bytehole to the town Bytepit, which is m kilometres away from Bytehole. Exactly d kilometres along the way from Bytehole to Bytepit, there is a base of n taxis, numbered from 1 to n. The taxi no. i has enough fuel to drive exactly xi kilometres.</p>

<p>Byteasar can change taxis at any point. All the taxis start at their base but need not return there. Your task is to determine whether Byteasar can be driven from Bytehole to Bytepit, and if so, what it the minimum number of taxis required for such a journey.</p>

### 입력 

 <p>The first line of the standard input holds three integers, m, d, and n (1 ≤ d ≤ m ≤ 10^18, 1 ≤ n ≤ 500,000), separated by single spaces. Those denote, respectively: the distance from Bytehole to Bytepit, the distance from Bytehole to the taxi base, and the number of taxis at the base. The second line of input contains n integers, x<sub>1</sub>,x<sub>2</sub>,…,x<sub>n</sub> (1 ≤ x<sub>i</sub> ≤ 10<sup>18</sup>), separated by single spaces. The number x<sub>i</sub> denotes the maximum distance (in kilometres) that the  i-th taxi can travel.</p>

### 출력 

 <p>Your program should print a single integer to the standard output: the minimum number of taxis Byteasar has to take to get from Bytehole to Bytepit. If getting there is impossible, your program should print the number 0.</p>

