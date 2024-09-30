# [Platinum III] Acordes intergaláticos - 15039 

[문제 링크](https://www.acmicpc.net/problem/15039) 

### 성능 요약

메모리: 18036 KB, 시간: 512 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 9월 30일 14:59:24

### 문제 설명

<p>A maratona de composição de sonatas para piano intergalático está tentando dificultar a vida dos competidores, pois cada vez mais seres de inteligência superior estão participando. O piano é composto de N teclas, numeradas de 0 a N − 1. O sistema tonal intergalático possui 9 notas musicais, com valores de 0 a 8. Inicialmente todas as teclas do piano estão associadas à mesma nota 1. O competidor vai tocar uma sequência de acordes. Cada acorde intergalático é composto por duas teclas distintas, a e b, 0 ≤ a < b < N. Quando o acorde é tocado, o piano vai emitir a nota mais frequente, f, entre todas as teclas do intervalo [a, b]. Se houver mais de uma nota mais frequente, ele emite a maior delas. Imediatamente ap´os emitir a nota, o piano muda a nota associada a todas as teclas do intervalo [a, b]. A nova nota associada à tecla k, a ≤ k ≤ b, será a anterior mais f, módulo 9.</p>

<p>Por exemplo, se em determinado momento as notas associadas a um piano de N = 15 teclas são</p>

<table class="table table-bordered" style="width:100%">
	<tbody>
		<tr>
			<th>teclas</th>
			<td>0</td>
			<td>1</td>
			<td>2</td>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>6</td>
			<td>7</td>
			<td>8</td>
			<td>9</td>
			<td>10</td>
			<td>11</td>
			<td>12</td>
			<td>13</td>
			<td>14</td>
		</tr>
		<tr>
			<th>notas</th>
			<td>2</td>
			<td>2</td>
			<td>1</td>
			<td><u>4</u></td>
			<td><u>5</u></td>
			<td><u>4</u></td>
			<td><u>3</u></td>
			<td><u>4</u></td>
			<td><u>8</u></td>
			<td><u>0</u></td>
			<td>1</td>
			<td>6</td>
			<td>2</td>
			<td>0</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p>e o acorde [3, 9] é tocado, então a nota mais frequente será 4 e as novas notas após o acorde serão:</p>

<table class="table table-bordered" style="width:100%">
	<tbody>
		<tr>
			<th>teclas</th>
			<td>0</td>
			<td>1</td>
			<td>2</td>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>6</td>
			<td>7</td>
			<td>8</td>
			<td>9</td>
			<td>10</td>
			<td>11</td>
			<td>12</td>
			<td>13</td>
			<td>14</td>
		</tr>
		<tr>
			<th>notas</th>
			<td>2</td>
			<td>2</td>
			<td>1</td>
			<td>8</td>
			<td>0</td>
			<td>8</td>
			<td>7</td>
			<td>8</td>
			<td>3</td>
			<td>4</td>
			<td>1</td>
			<td>6</td>
			<td>2</td>
			<td>0</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p>Dada a sequência de Q acordes, seu programa deve imprimir as notas que estarão associadas às teclas do piano após todos os acordes da sequência terem sido tocados.</p>

### 입력 

 <p>A primeira linha da entrada contém dois inteiros, N (2 ≤ N ≤ 100000), e Q (1 ≤ Q ≤ 100000), respectivamente o número de teclas do piano intergalático e a quantidade de acordes. As Q linhas seguintes contêm, cada uma, dois inteiros A e B, (0 ≤ A < B < N), representando um acorde.</p>

### 출력 

 <p>Seu programa deve imprimir N inteiros, um por linha, representando as notas associadas às teclas do piano, após todos os acordes terem sido tocados.</p>

