#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, m, k;
string str;
ll fr[1010100];
ll bck[1010100];

void solve() {
    cin >> str;
    n = str.length();
    // 일단 K를 맨 왼쪽으로 옮기자 
    ll ans = 0;
    ll cnt = 0;
    string s = "";
    for(int i = 0 ; i < n; i++){
        if(str[i] != 'K'){
            cnt++;
            s += str[i];
        }
        else{
            ans += cnt;
        }
    }
    n = s.length();
    cnt = 0;
    bool flag = 0;
    bck[n + 1] = 1e12;
    fr[0] = 1e12;
    // 앞에서부터 
    for(int i = 1; i <= n; i++){
        fr[i] = fr[i-1];
        if(s[i-1] == 'P'){
            cnt++;
        }
        else{   
            if(!flag){
                flag = 1;
                fr[i] = 0;
            }
            fr[i] += cnt;
        }
    }
    cnt = 0;
    flag = 0;
    for(int i = n; i >= 1; i--){
        bck[i] = bck[i+1];
        if(s[i-1] == 'P'){
            cnt++;
        }
        else{
            if(!flag){
                flag = 1;
                bck[i] = 0;
            }
            bck[i] += cnt;
        }
    }
    ll ans2 = 1e12;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == 'C'){
            flag = 1;
        }
        if(flag){
            ans2 = min(ans2, fr[i] + bck[i+1]);
        }
        // cout << i << ' ' << fr[i] << ' ' << bck[i+1] << '\n';
    }
    
    cout << ans + ans2<< '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}