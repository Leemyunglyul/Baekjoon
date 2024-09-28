# [Platinum II] Simple - 21958 

[문제 링크](https://www.acmicpc.net/problem/21958) 

### 성능 요약

메모리: 35224 KB, 시간: 324 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 9월 28일 22:00:38

### 문제 설명

<p>You are given a sequence of N numbers and Q queries:</p>

<ul>
	<li>0 a b val : the number val will be added to all of the numbers from the interval [a,b]</li>
	<li>1 a b : you need to print the minimum even number and the maximum odd number form the interval [a,b]; if one of these numbers does not exist, -1 will be printed in its place</li>
</ul>

<p>Answer all of the type 1 queries.</p>

### 입력 

 <p>The first line contains one integer: N. The second line contains N integers, representing the numbers from the sequence. The third line contains one integer: Q, and the following Q lines contain Q queries, as described in the statement.</p>

### 출력 

 <p>The output contains the answers to all of the type 1 queries, one per line.</p>

