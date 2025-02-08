#include <string>
#include <vector>
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll cnt[10][10];
pair<ll,ll>mt[10];
ll dp[101010][10][10];
string str;
ll ans = 1e9;

ll solve(ll n, ll a, ll b){
    if(n == str.length() + 1){
        return 0;
    }
    ll  & ret= dp[n][a][b];
    if(ret != -1) return ret;
    ret = 1e12;
    ll nxt = str[n-1] -'0';
    if(nxt != b){
        ret = min(ret, solve(n+1, nxt , b) + cnt[a][nxt]);
    }
    if(nxt != a){
        ret = min(ret, solve(n+1, a , nxt)+cnt[b][nxt]);
    }
    return ret;
}

int solution(string numbers) {
    str = numbers;
    ll answer = 1e18;
    mt[0] = {4, 2};
    for(int i = 1; i <= 9 ; i++){
        mt[i] = {(i + 2) / 3, (i-1) % 3 + 1};
    }
    for(int i = 0 ; i <=9; i++){
        for(int j= 0 ; j <= 9; j++){
            if(i == j) cnt[i][j] = 1;
            else{
                ll gap1 = abs(mt[i].first - mt[j].first);
                ll gap2 = abs(mt[i].second -mt[j].second);
                ll mn = min(gap1, gap2);
                ll mx = max(gap1, gap2);
                cnt[i][j] = mn * 3 + (mx - mn) * 2;
            }
        }
    }
    ll n = numbers.length();
    memset(dp, -1, sizeof(dp));
    answer = solve(1, 4, 6);
    return answer;
}