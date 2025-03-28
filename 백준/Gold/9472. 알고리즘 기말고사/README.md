# [Gold II] 알고리즘 기말고사 - 9472 

[문제 링크](https://www.acmicpc.net/problem/9472) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

조합론, 다이나믹 프로그래밍, 포함 배제의 원리, 수학

### 제출 일자

2025년 3월 2일 23:04:46

### 문제 설명

<p>알고리즘 기말고사는 용어와 정의를 선으로 연결하는 문제만 나온다. 왼쪽에는 용어 N개, 오른쪽에는 정의 N개가 한 줄로 나열되어 있다. 학생들은 각 용어에 해당하는 정의를 선으로 그려야 한다.</p>

<p>선영이는 자신의 뛰어난 프로그래밍 실력을 믿고 공부를 하지 않았다. 하지만, 기말고사는 프로그래밍 실력과 관계없는 문제만 나왔다. 따라서, 선영이는 문제를 모두 찍으려고 한다.</p>

<p>S(N,k)를 선영이가 문제를 모두 풀었을 때, 적어도 위에서부터 처음 k개 용어는 반드시 틀리는 경우의 수라고 하자.</p>

<p>N과 k가 주어졌을 때, S(N,k)를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 테스트 케이스 번호와 두 정수 N과 k가 주어진다. (1 ≤ N ≤ 17, 0 ≤ k ≤ N)</p>

### 출력 

 <p>각 테스트 케이스 마다 테스트 케이스 번호와 S(N,k)를 출력한다.</p>

