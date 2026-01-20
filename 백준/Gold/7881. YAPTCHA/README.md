# [Gold II] YAPTCHA - 7881 

[문제 링크](https://www.acmicpc.net/problem/7881) 

### 성능 요약

메모리: 8856 KB, 시간: 192 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2026년 1월 20일 18:59:58

### 문제 설명

<p>선영이는 문제를 풀 때마다 Practice Log에 문제의 풀이법을 올려놓는다. 이 사이트는 매우 유명해졌고, 하루에 백만명이 들어오는 사이트가 되었다.</p>

<p>선영이는 풀이를 읽지 않고 소스만 긁어서 온라인 저지에 제출하는 사람들을 정말 싫어한다. 이런한 일을 막기 위해서 Yet-Another-Public-Turing-Test-to-Tell-Computers-and-Humans-Apart를 홈페이지에 추가하기로 했다.</p>

<p>선영이가 만든 YAPTCHA 테스트는 매우 어려워서 박사학위를 받은 학생이나 교수도 쉽게 풀 수 없다. 문제의 풀이법을 보고싶어하는 상근이는 자동으로 테스트를 푸는 프로그램을 만들려고 한다.</p>

<p>선영이의 홈페이지에 들어가면 자연수 n과 다음과 같은 식이 주어진다. 식을 계산한 뒤, S<sub>n</sub>을 입력하면 문제의 풀이를 볼 수 있다. n이 주어졌을 때, S<sub>n</sub>을 구하는 프로그램을 작성하시오.</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.032em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munderover space="4"><mjx-over style="padding-bottom: 0.192em; padding-left: 0.51em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.086em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c5B TEX-S3"></mjx-c></mjx-mo><mjx-mfrac><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c36"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c21"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mrow><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mrow space="3"><mjx-mo class="mjx-s3"><mjx-c class="mjx-c5B TEX-S3"></mjx-c></mjx-mo><mjx-mfrac><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c36"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c21"></mjx-c></mjx-mo></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mrow><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-s3"><mjx-c class="mjx-c5D TEX-S3"></mjx-c></mjx-mo></mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c5D TEX-S3"></mjx-c></mjx-mo></mjx-mrow></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msub><mi>S</mi><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></msub><mo>=</mo><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>k</mi><mo>=</mo><mn>1</mn></mrow><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">[</mo><mfrac><mrow><mo stretchy="false">(</mo><mn>3</mn><mi>k</mi><mo>+</mo><mn>6</mn><mo stretchy="false">)</mo><mo>!</mo><mo>+</mo><mn>1</mn></mrow><mrow><mn>3</mn><mi>k</mi><mo>+</mo><mn>7</mn></mrow></mfrac><mo>−</mo><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">[</mo><mfrac><mrow><mo stretchy="false">(</mo><mn>3</mn><mi>k</mi><mo>+</mo><mn>6</mn><mo stretchy="false">)</mo><mo>!</mo></mrow><mrow><mn>3</mn><mi>k</mi><mo>+</mo><mn>7</mn></mrow></mfrac><mo data-mjx-texclass="CLOSE">]</mo></mrow><mo data-mjx-texclass="CLOSE">]</mo></mrow></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[S_{n} =\sum _{ k=1 }^{ n }{ \left[ \frac{(3k+6)!+1}{3k+7}-\left[ \frac{(3k+6)!}{3k+7} \right]  \right]  }  \]</span> </mjx-container></p>

<p>[x]는 x보다 크지 않은 가장 큰 정수를 말한다.</p>

### 입력 

 <p>첫째 줄에 쿼리의 수 t (t ≤ 10<sup>6</sup>)가 주어진다. 각 쿼리는 자연수 n 하나로 이루어져 있다. (1 ≤ n ≤ 10<sup>6</sup>)</p>

### 출력 

 <p>입력으로 주어진 n에 대해서 S<sub>n</sub>을 출력한다. </p>

