# [Gold I] String Game - 11307 

[문제 링크](https://www.acmicpc.net/problem/11307) 

### 성능 요약

메모리: 3308 KB, 시간: 4 ms

### 분류

게임 이론, 문자열

### 제출 일자

2025년 2월 16일 17:50:33

### 문제 설명

<p>Alice and Bob are playing the following game with strings of letters.</p>

<p>Before the game begins, an initial string and a target string are decided. The initial string is at least as long as the target string. Then, Alice and Bob take turns, starting with the initial string. Bob goes first. In each turn, the current player removes either the first or the last letter of the current string. Once the length of the current string becomes equal to the length of the target string, the game stops. If the string at the end of the game is equal to the target string, Alice wins the game; otherwise Bob wins.</p>

<p>Determine who will win the game if both players are playing optimally.</p>

### 입력 

 <p>Each test case starts with N, the number of inputs to process. Each input consists of one line, which contains the initial string, followed by a space, followed by the target string. Each string consists of only lowercase letters. The total input length will be less than 500000 characters.</p>

### 출력 

 <p>For each input, output the winner, which will either be Alice or Bob.</p>

