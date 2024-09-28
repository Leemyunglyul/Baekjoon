# [Platinum III] Alakazam - 18619 

[문제 링크](https://www.acmicpc.net/problem/18619) 

### 성능 요약

메모리: 18784 KB, 시간: 424 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 수학, 확률론, 세그먼트 트리

### 제출 일자

2024년 9월 28일 23:50:09

### 문제 설명

<p>Hello, fellow Pok´emon trainer! So you’re on a safari as well? It’s nice you’re here, you were the one to spot an Alakazam colony!</p>

<p>The colony consists of n Alakazam specimens. Each of them holds a number of spoons increasing their psychic abilities. They’ve just formed up in a line in order to perform a psychic training. It’s not just any kind of training — it’s the teleportation training!</p>

<p>The training consists of a number of group teleportations. During each teleportation, a contiguous group of Alakazam specimens disappear and then materialize in the same positions as before, but in a totally random order.</p>

<p>Just before the training, you counted the spoons held by each Alakazam. However, after the training started, you were too far away to count the spoons — you only saw the teleportations. Basing on your observations, can you predict how many spoons are held by Alakazam at some positions in the line throughout the training? Obviously, as the process is random, we’re only asking you about the expected number of spoons.</p>

### 입력 

 <p>The first line contains two integers n, q (1 ≤ n ≤ 250 000, 1 ≤ q ≤ 250 000) — the number of Alakazam in the line and the number of actions during the training. The following line contains n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>6</sup>) — the number of spoons held by each specimen in the line.</p>

<p>Each of the next q lines describes a single action and is in one of the following formats:</p>

<ul>
	<li>shuffle l r (1 ≤ l ≤ r ≤ n) — the group of Alakazam between the l-th and the r-th specimen (inclusive) teleport and materialize in random order.</li>
	<li>get i (1 ≤ i ≤ n) — you need to predict the expected number of spoons held by the i-th Alakazam in the line.</li>
</ul>

<p>There will be at least one get query in the file.</p>

### 출력 

 <p>For each get query, output a single decimal number: the expected number of spoons held by the specified Alakazam.</p>

<p>Your answer will be considered correct if its absolute or relative error doesn’t exceed 10<sup>−9</sup>.</p>

