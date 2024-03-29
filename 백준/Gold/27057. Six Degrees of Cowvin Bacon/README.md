# [Gold IV] Six Degrees of Cowvin Bacon - 27057 

[문제 링크](https://www.acmicpc.net/problem/27057) 

### 성능 요약

메모리: 2772 KB, 시간: 0 ms

### 분류

플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2024년 3월 29일 22:20:25

### 문제 설명

<p>The cows have been making movies lately, so they are ready to play a variant of the famous game "Six Degrees of Kevin Bacon".</p>

<p>The game works like this: each cow is considered to be zero degrees of separation (degrees) away from herself. If two distinct cows have been in a movie together, each is considered to be one 'degree' away from the other.  If a two cows have never worked together but have both worked with a third cow, they are considered to be two 'degrees' away from each other (counted as: one degree to the cow they've worked with and one more to the other cow).  This scales to the general case.</p>

<p>The N (2 ≤ N ≤ 300) cows are interested in figuring out which cow has the smallest average degree of separation from all the other cows. excluding herself of course. The cows have made M (1 ≤ M ≤ 10000) movies and it is guaranteed that some relationship path exists between every pair of cows.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Each input line contains a set of two or more space-separated integers that describes the cows appearing in a single movie.  The first integer is the number of cows participating in the described movie, (e.g., Mi); the subsequent Mi integers tell which cows were.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is 100 times the shortest mean degree of separation of any of the cows.</li>
</ul>

