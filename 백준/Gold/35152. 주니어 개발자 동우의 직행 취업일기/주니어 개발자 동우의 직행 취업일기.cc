#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, m, k;
string str;

void solve() {
    cin >> n;
    vector<pair<ll,ll>>ans;
    ans.push_back({1, 2});

    if(n < 999998){
        ll cur = 4;
        ll par = 3;
        ans.push_back({2, 3});
        for(int i = 1; i <= n; i++){
            ans.push_back({par, cur});
            cur++;
        }
    }
    if(n == 999999){
        // 3, 333333 으로 분할
        ll cur = 4;
        ll par = 3;
        ans.push_back({2, 3});
        for(int i = 1; i <= 3; i++){
            ans.push_back({par, cur});
            cur++;
        }
        par = cur;
        cur++;
        ans.push_back({2, par});
        for(int i = 1; i <= 333333; i++){
            ans.push_back({par, cur});
            cur++;
        }
    }
    if(n == 1000000){
        ll cur = 4;
        ll par = 3;
        ans.push_back({2, 3});
        for(int i = 1; i <= 2; i++){
            ans.push_back({par, cur});
            cur++;
        }
        par = cur;
        cur++;
        ans.push_back({2, par});
        for(int i = 1; i <= 500000; i++){
            ans.push_back({par, cur});
            cur++;
        }
    }
    if(n == 999998){
        ll cur = 4;
        ll par = 3;
        ans.push_back({2, 3});
        for(int i = 1; i <= 2; i++){
            ans.push_back({par, cur});
            cur++;
        }
        par = cur;
        cur++;
        ans.push_back({2, par});
        for(int i = 1; i <= 499999; i++){
            ans.push_back({par, cur});
            cur++;
        }
    }

    cout << ans.size() + 1<< '\n';
    for(auto a : ans){
        cout << a.first << ' ' << a.second << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}