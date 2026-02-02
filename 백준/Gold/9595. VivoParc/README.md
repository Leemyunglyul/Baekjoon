# [Gold I] VivoParc - 9595 

[문제 링크](https://www.acmicpc.net/problem/9595) 

### 성능 요약

메모리: 2160 KB, 시간: 36 ms

### 분류

그래프 이론, 그래프 탐색, 깊이 우선 탐색, 백트래킹

### 제출 일자

2026년 2월 2일 14:52:46

### 문제 설명

<p>Vivoparc is a zoological park located in Valencia. It has recently added a new area formed by a big plane savanna grassland divided into several enclosures.</p>

<p>Our purpose is to assign one animal of the 4 different species (lions, leopards, tigers, and panthers) to each of the new VivoParc enclosures. These animals are very territorial therefore we must be sure that no animal can see other animal of its own species from its enclosure. The Vivoparc manager has sent us a file with the visibility from the different enclosures and we have to assign one species to each enclosure. At the end of the process, all the enclosures must have an assigned species.</p>

### 입력 

 <p>The first line of the input file contains the number of enclosures (N ≤ 100). Each of the following lines contain a visibility restriction: 1-3 means that animals in enclosure #1 can see animals in enclosure #3 and animals in enclosure #3 can see animals in enclosure #1. Note that the Vivoparc manager is not a very well organized person and therefore, some data appearing in the file may be redundant.</p>

### 출력 

 <p>The output file contains one of all the possible species assignation. The file consists of a line per enclosure and each line contains the number of the enclosure followed by the assigned species (1= Lion, 2= Leopard, 3= Tiger, 4= Panther). Enclosures assignation must appear in ascending order.</p>

