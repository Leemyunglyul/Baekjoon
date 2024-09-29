# [Platinum III] Pikimad teed puus - 7206 

[문제 링크](https://www.acmicpc.net/problem/7206) 

### 성능 요약

메모리: 22596 KB, 시간: 116 ms

### 분류

자료 구조, 오일러 경로 테크닉, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 트리

### 제출 일자

2024년 9월 29일 22:23:56

### 문제 설명

<p>Jaak ja Jaagup osalesid ühel programmeerimisvõistlusel tiimina, teenisid suure koguse ˇsokolaadi ja tahavad selle omavahel ära jagada. Mõlemad on küllalt ülbed ja kumbki arvab, et tema panus tiimi edukusse oli suurem kui teise oma.</p>

<p>Nad mõtlesid ˇsokolaadi jagamiseks välja susteemi, mis tundus m ¨ õlemale õiglane. Nimelt esitavad nad üksteisele kordamööda informaatikaülesandeid. Teine peab esitatud ülesande võimalikult kiiresti ja elegantselt ära lahendama ja siis võrreldakse lahendamise aega ja elegantsust ülesande esitaja omadega. Šokolaad jagatakse vastavalt sellele, kumb on teise ülesannete lahendamisel edukam.</p>

<p>Jaagup esitas Jaagule järgmise ülesande:</p>

<blockquote>
<p>On antud puu, mille N tippu on tähistatud 1, 2, . . . , N. Lisaks on puu igal serval e kaal w(e). Puu kohta esitatakse Q päringut kujul:</p>

<ol>
	<li>Sea tipust i selle ülemusse minema serva uueks kaaluks w'</li>
	<li>Leia tipu i alampuus tipust i väljuvate lihtsate teede kaalude maksimum. Tee kaaluks nimetame kõigi teele jäävate servade kaalude summat. Lihtsaks nimetame teed, mis ei läbi uhtki tippu korduvalt.</li>
</ol>
</blockquote>

<p>Jaak jäi selle ülesandega hätta ja otsustas abi küsida. Lahendada Jaagule antud ülesanne ära.</p>

### 입력 

 <p>Tekstifaili esimesel real on täisarv N (1 ≤ N ≤ 10<sup>5</sup>). Teisel real on N täisarvu x<sub>1</sub>, x<sub>2</sub>, . . . , x<sub>N</sub>, kus x<sub>i</sub> tähistab tipu i ülemust (kui i on puu juur, siis x<sub>i</sub> = 0). Kolmandal real on N täisarvu w<sub>1</sub>, w<sub>2</sub>, . . . , w<sub>N</sub>, kus w<sub>i</sub> on tipu i ja selle ülemuse vahel oleva serva esialgne kaal (−10<sup>9</sup> ≤ w<sub>i</sub> ≤ 10<sup>9</sup>, i ∈ 1 . . . N).</p>

<p>Neljandal real on täisarv Q (1 ≤ Q ≤ 10<sup>5</sup>). Järgmisel Q real on igaühel esimesena täisarv T (1 ≤ T ≤ 2), mis tähistab operatsiooni tüüpi, ja vastavalt sellele kas täisarvud i (1 ≤ i ≤ N) ja w' (−10<sup>9</sup> ≤ w' ≤ 10<sup>9</sup>) või lihtsalt täisarv i.</p>

### 출력 

 <p>Tekstifaili väljastada 2. tüüpi päringute vastused, igaüks eraldi reale, päringute sisendis esinemise järjekorras.</p>

