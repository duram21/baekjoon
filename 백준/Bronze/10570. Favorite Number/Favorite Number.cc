#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, k, m, q;
string str;


void solve() {
    cin >> n;
    map<ll, ll>mp;
    for(int i =  1; i <= n; i++){
        cin >> a;
        mp[a]++;
    }
    ll cur = -1;
    ll ans = 0;
    for(auto nxt : mp){
        if(cur < nxt.second){
            ans = nxt.first;
            cur = nxt.second;
        }
    }    
    cout << ans << '\n';
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    ll tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}