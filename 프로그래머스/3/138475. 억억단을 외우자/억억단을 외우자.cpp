#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll dp[5050505];
ll ans[5010101];
ll cnt[5010101];

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    for(int i = 1; i <= e; i++){
        for(int j = 1; i <= e; j++){
            if(i * j > e) break;
            dp[i * j] ++;
        }
    }
    dp[1] = 1;
    vector<pair<ll,ll>>tmp;
    ll n = starts.size();
    ans[e] = e;
    cnt[e] = dp[e];
    for(int i = e-1; i >= 1; i --){
        if(cnt[i+1] <= dp[i]){
            ans[i] = i;
            cnt[i] = dp[i];
            
        }
        else{
            ans[i] =ans[i+1];
            cnt[i] = cnt[i+1];
        }
    }
    
    for(int i = 0; i < n; i++){
        answer.push_back(ans[starts[i]]);
    }
    return answer;
}