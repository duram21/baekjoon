# [Platinum II] 벡터의 합 - 16885 

[문제 링크](https://www.acmicpc.net/problem/16885) 

### 성능 요약

메모리: 11444 KB, 시간: 56 ms

### 분류

분할 정복, 기하학, 정렬, 스위핑

### 제출 일자

2025년 6월 6일 17:42:41

### 문제 설명

<p>2차원 벡터 N개가 있다. 각각의 벡터는 좌표에 -1을 곱하는 연산을 적용할 수 있다. 예를 들어, v = (x, y) 라면, 아래 4가지 중 하나로 변형할 수 있다.</p>

<ul>
	<li>1: (x, y)</li>
	<li>2: (-x, y)</li>
	<li>3: (x, -y)</li>
	<li>4: (-x, -y)</li>
</ul>

<p>N개의 벡터 중 두 개 v<sub>i</sub>, v<sub>j</sub>를 골라 |v<sub>i</sub> + v<sub>j</sub>|의 최솟값을 구하는 프로그램을 작성하시오. 벡터에는 위의 연산을 적용해 4가지 중 하나로 변형할 수 있다.</p>

### 입력 

 <p>첫째 줄에 벡터의 개수 N(2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에 i번째 벡터 v<sub>i</sub>의 좌표 x<sub>i</sub>, y<sub>i</sub>(-10,000 ≤ x, y ≤ 10,000)가 한 줄에 하나씩 주어진다.</p>

### 출력 

 <p>첫째 줄에 네 개의 정수 i, k<sub>1</sub>, j, k<sub>2</sub>를 공백으로 구분해 출력한다. i와 j는 고른 벡터의 인덱스이고, k<sub>1</sub>, k<sub>2</sub>는 적용한 연산의 번호이다. 최소가 되는 정답이 여러가지인 경우에는 아무거나 출력한다.</p>

