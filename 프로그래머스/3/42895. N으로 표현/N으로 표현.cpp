#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int solution(int N, int number) {
    int answer = -1;
    
    set<ll>s[10];
    ll cur = 0;
    for(int i = 1; i <= 8; i++){
        cur = cur * 10 + N;
        s[i].insert(cur);
    }
    for(int i = 2; i <= 8; i++){
        for(int j = 1; j < i ; j++){
            for (int a : s[j]) {
                for (int b : s[i - j ]) {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0) {
                        s[i].insert(a / b);
                    }
                }
            }
        }
    }
    for(int i = 1; i <= 8 ; i++){
        if(s[i].find(number ) != s[i].end()){
            answer = i;
            break;
        }
    }
    return answer;
}