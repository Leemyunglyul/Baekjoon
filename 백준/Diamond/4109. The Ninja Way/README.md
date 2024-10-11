# [Diamond V] The Ninja Way - 4109 

[문제 링크](https://www.acmicpc.net/problem/4109) 

### 성능 요약

메모리: 2168 KB, 시간: 188 ms

### 분류

벨만–포드, 그래프 이론, 최단 경로

### 제출 일자

2024년 10월 11일 16:11:48

### 문제 설명

<p>As we all know, Ninjas travel by jumping from treetop to treetop. A clan of Ninjas plans to use N trees to hone their tree hopping skills. They will start at the shortest tree and make N-1 jumps, with each jump taking them to a taller tree than the one they‟re jumping from. When finished, they will have been on every tree exactly once, traversing them in increasing order of height, and ending up on the tallest tree.</p>

<p>The ninjas can travel for at most a certain horizontal distance D in a single jump. To make this as much fun as possible, the Ninjas want to maximize the distance between the positions of the shortest tree and the tallest tree.</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/4109/1.png" style="height:177px; width:597px"></p>

<p>The ninjas are going to plant the trees subject to the following constraints.</p>

<ul>
	<li>All trees are to be planted along a one-dimensional path.</li>
	<li>Trees must be planted at integer locations along the path, with no two trees at the same location.</li>
	<li>Trees must be arranged so their planted ordering from left to right is the same as their ordering in the input. They must NOT be sorted by height, or reordered in any way. They must be kept in their stated order.</li>
	<li>The Ninjas can only jump so far, so every tree must be planted close enough to the next taller tree. Specifically, they must be no further than D apart on the ground (the difference in their heights doesn‟t matter).</li>
</ul>

<p>Given N trees, in a specified order, each with a distinct integer height, help the ninjas figure out the maximum possible distance they can put between the shortest tree and the tallest tree, and be able to use the trees for training.</p>

### 입력 

 <p>There will be multiple test cases. Each test case begins with a line containing two integers N (1 ≤ N ≤ 1000) and D (1 ≤ D ≤10<sup>6</sup>). The next N lines each contain a single integer, giving the heights of the N trees, in the order that they should be planted. Within a test case, all heights will be unique. The last test case is followed by a line with two 0's.</p>

### 출력 

 <p>For each test case, output a line with a single integer representing the maximum distance between the shortest and tallest tree, subject to the constraints above, or -1 if it is impossible to lay out the trees. Do not print any blank lines between answers.</p>

