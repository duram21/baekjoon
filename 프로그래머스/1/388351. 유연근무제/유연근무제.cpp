#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    ll cnt = 0;
    ll n = schedules.size();
    
    for(int i = 0 ; i < n; i++){
        ll t = schedules[i];
        t += 10;
        if( t % 100 >= 60){
            t -= 60;
            t += 100;
        }
        bool flag = 1;
        for(int j = 0 ; j < 7; j++){
            ll arrive = timelogs[i][j];
            ll day = (startday + j) % 7;
            if(day == 0 || day == 6) continue;
            
            if(arrive > t)flag= 0;
            
        }
        if(flag) answer++;
    }
    
    
    return answer;
}