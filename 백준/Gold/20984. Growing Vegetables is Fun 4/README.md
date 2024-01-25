# [Gold I] Growing Vegetables is Fun 4 - 20984 

[문제 링크](https://www.acmicpc.net/problem/20984) 

### 성능 요약

메모리: 6708 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 누적 합

### 제출 일자

2024년 1월 26일 02:20:42

### 문제 설명

<p>Bitaro likes gardening. He is now growing plants called Biba-herbs in the garden. There are N Biba-herbs in the garden, planted in a line from the west to the east. The Biba-herbs are numbered from 1 to N from the west to the east. Now, the height of the Biba-herb i (1 ≤ i ≤ N) is A<sub>i</sub>.</p>

<p>Due to the breed improvement, if Bitaro waters a Biba-herb once, then its height increases by 1. Since he wants to decorate the garden, he will water the Biba-herbs several times so that the following condition is satisfied.</p>

<ul>
	<li>After Bitaro finishes watering, let Bi be the height of the Biba-herb i. Then, there exists an integer k (1 ≤ k ≤ N) such that B<sub>j</sub> < B<sub>j+1</sub> holds for every 1 ≤ j ≤ k − 1, and B<sub>j</sub> > B<sub>j+1</sub> holds for every k ≤ j ≤ N − 1.</li>
</ul>

<p>However, Bitaro is not good at watering. When he waters Biba-herbs, he can only water consecutive Bibaherbs in an interval. In other words, he chooses integers L and R (1 ≤ L ≤ R ≤ N) and waters the Biba-herbs L, L + 1, . . . , R.</p>

<p>Bitaro wants to minimize the number of times of watering.</p>

<p>Write a program which, given the number of Biba-herbs and their current heights, calculates the minimum number of times of watering so that the above condition is satisfied.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N
A<sub>1</sub> · · · A<sub>N</sub></pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum number of times of watering.</p>

