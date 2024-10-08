# [Platinum III] 욱제와 그의 팬들 - 15352 

[문제 링크](https://www.acmicpc.net/problem/15352) 

### 성능 요약

메모리: 30656 KB, 시간: 832 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2024년 10월 9일 16:47:00

### 문제 설명

<p>욱제에게는 K개의 팬클럽이 있습니다. 욱제가 성인이 된 것을 기념하여 개최하는 욱제의 팬미팅에 N명의 팬이 모였습니다. N명의 팬들은 각각 순서대로 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub> 번 팬클럽에 소속되어 있으며, 등록번호 1, 2, ..., N을 가집니다. 팬들은 1, 2, ..., N번 순서로 서 있습니다.</p>

<p>할 일이 없었던 욱제는 Q번 어떠한 행동을 하기로 합니다. 행동에는 두가지 종류가 있습니다 :</p>

<ul>
	<li>행동 1 : 욱제는 팬을 한 명 골라 진정한 팬이 아니라는 이유로 팬미팅에서 퇴출시킵니다.</li>
	<li>행동 2 : 욱제는 팬을 한 명 골라 그 팬을 포함해 양 옆으로 연속적으로 같은 팬클럽인 사람들에게 헌신적인 팬이 되어준 보상으로써 선물을 줍니다.</li>
</ul>

<p>욱제는 Q번의 행동을 수행한 후 너무 질린 나머지 "나보다 알고리즘 못하는 사람들 다 나가"를 시전해 팬미팅을 종료시켰습니다. 욱제는 팬미팅이 끝난 후 팬들에게 준 선물의 수를 알고 싶어합니다. 욱제를 도와주세요.</p>

### 입력 

 <p>첫 번째 줄에 K와 N이 입력됩니다. (1 ≤ K, N ≤ 10<sup>6</sup>)</p>

<p>두 번째 줄에 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 입력됩니다. (1 ≤ A<sub>i</sub> ≤ K)</p>

<p>세 번째 줄에 Q가 입력됩니다. (0 ≤ Q ≤ 3 × 10<sup>6</sup>)</p>

<p>Q개의 줄 동안 숫자 a와 b가 입력됩니다. (1 ≤ a ≤ 2, 1 ≤ b ≤ N)</p>

<p>a가 1일 경우엔 등록번호 b번 사람을 대상으로 행동 1을 시행하며. 이는 같은 팬에게 중복으로 발생하지 않음이 보장됩니다.</p>

<p>a가 2일 경우엔 등록번호 b번 사람을 기준으로 행동 2를 시행합니다. 퇴출된 사람은 대상이 되지 않습니다.</p>

### 출력 

 <p>Q번의 행동을 시행한 후 욱제가 팬들에게 준 총 선물의 수를 출력합니다. 욱제는 선물을 무한히 많이 가지고 있기 때문에, 선물이 부족해 선물을 줄 수 없는 경우는 없습니다.</p>

