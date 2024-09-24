# [Platinum II] Salary Inequity - 10565 

[문제 링크](https://www.acmicpc.net/problem/10565) 

### 성능 요약

메모리: 165908 KB, 시간: 620 ms

### 분류

자료 구조, 오일러 경로 테크닉, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 트리

### 제출 일자

2024년 9월 25일 08:50:45

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/salary.png" style="height:155px; width:173px"></p>

<p>There is a large company of N employees. With the exception of one employee, everyone has a direct supervisor. The employee with no direct supervisor is indirectly a supervisor of all other employees in the company. We say that employee X is a subordinate of employee Y if either Y is the direct supervisor of X, or the direct supervisor of X is a subordinate of Y .</p>

<p>One day, the HR department decides that it wants to investigate how much inequity there is in the company with respect to salaries. For a given employee, the inequity of the employee is the difference between the minimum salary of that employee and all his/her subordinates and the maximum salary of that employee and all his/her subordinates.</p>

<p>HR wants to be able to compute the inequity for any employee quickly. However, this is complicated by the fact that an employee will sometimes give himself/herself, along with all his/her subordinates, a raise. Can you help?</p>

### 입력 

 <p>The first line of your input file contains a number T representing the number of companies you will be analyzing for inequity. T will be at most 20.</p>

<p>For each company, there will be a line containing an integer N, representing the number of employees at the company. Each employee is assigned an ID which is a unique integer from 1 to N. The next line will contain N − 1 integers. The Kth integer in that line is the ID of the direct supervisor of employee (K + 1). The next line will contain N integers, the Kth integer in this line being the salary of employee K. The next line contains an integer Q, the number of events that you will need to process. There are two types of events to process - raises and inequity queries. In the event of a raise, the line will start with the letter R followed by the ID of the employee and an integer representing the increase in salary for that employee and all his/her subordinates. In the event of an inequity query, the line will start with the letter Q followed by the ID of the employee for whom inequity needs to be determined.</p>

<ul>
	<li>2 <= N <= 1,000,000</li>
	<li>1 <= Q <= 10,000</li>
</ul>

<p>For every employee K, the ID of his/her supervisor will be less than K. Initial salaries will range from 1 to 1,000. No raise will exceed 1,000.</p>

### 출력 

 <p>For each inequity query, print the inequity of the employee on its own line.</p>

