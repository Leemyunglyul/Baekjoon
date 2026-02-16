# [Gold III] Walking Ant - 22844 

[문제 링크](https://www.acmicpc.net/problem/22844) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2026년 2월 17일 00:20:44

### 문제 설명

<p>Ants are quite diligent. They sometimes build their nests beneath flagstones.</p>

<p>Here, an ant is walking in a rectangular area tiled with square flagstones, seeking the only hole leading to her nest.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9bed007f-b595-4477-b1e6-90a9f011c2ad/-/preview/" style="width: 481px; height: 333px;"></p>

<p>The ant takes exactly one second to move from one flagstone to another. That is, if the ant is on the flagstone with coordinates (x,y) at time t, she will be on one of the five flagstones with the following coordinates at time t + 1:</p>

<p>(x, y), (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1).</p>

<p>The ant cannot go out of the rectangular area. The ant can visit the same flagstone more than once.</p>

<p>Insects are easy to starve. The ant has to go back to her nest without starving. Physical strength of the ant is expressed by the unit "HP". Initially, the ant has the strength of 6 HP. Every second, she loses 1 HP. When the ant arrives at a flagstone with some food on it, she eats a small piece of the food there, and recovers her strength to the maximum value, i.e., 6 HP, without taking any time. The food is plenty enough, and she can eat it as many times as she wants.</p>

<p>When the ant's strength gets down to 0 HP, she dies and will not move anymore. If the ant's strength gets down to 0 HP at the moment she moves to a flagstone, she does not effectively reach the flagstone: even if some food is on it, she cannot eat it; even if the hole is on that stone, she has to die at the entrance of her home.</p>

<p>If there is a puddle on a flagstone, the ant cannot move there.</p>

<p>Your job is to write a program which computes the minimum possible time for the ant to reach the hole with positive strength from her start position, if ever possible.</p>

### 입력 

 <p>The input consists of multiple maps, each representing the size and the arrangement of the rectangular area. A map is given in the following format.</p>

<pre>w h
d<sub>11</sub> d<sub>12</sub> d<sub>13</sub> ... d<sub>1w</sub>
d<sub>21</sub> d<sub>22</sub> d<sub>23</sub> ... d<sub>2w</sub>
     ...
d<sub>h1</sub> d<sub>h2</sub> d<sub>h3</sub> ... d<sub>hw</sub></pre>

<p>The integers w and h are the numbers of flagstones in the x- and y-directions, respectively. w and h are less than or equal to 8. The integer d<sub>yx</sub> represents the state of the flagstone with coordinates (x, y) as follows.</p>

<ul>
	<li>0: There is a puddle on the flagstone, and the ant cannot move there.</li>
	<li>1, 2: Nothing exists on the flagstone, and the ant can move there. '2' indicates where the ant initially stands.</li>
	<li>3: The hole to the nest is on the flagstone.</li>
	<li>4: Some food is on the flagstone.</li>
</ul>

<p>There is one and only one flagstone with a hole. Not more than five flagstones have food on them.</p>

<p>The end of the input is indicated by a line with two zeros.</p>

<p>Integer numbers in an input line are separated by at least one space character.</p>

### 출력 

 <p>For each map in the input, your program should output one line containing one integer representing the minimum time. If the ant cannot return to her nest, your program should output -1 instead of the minimum time.</p>

