#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;
ll pos[505];
ll power[505];
ll flag[505];
vector<ll>es[505];
vector<ll>se[505];
ll dp[505][505];
ll mod = 1e3;

ll func(ll l, ll r){
    ll &ret = dp[l][r];
    if(ret != -1) return ret;
    if(l == n  && r== n) return 1;
    ret = 0;

    for(auto nxt : se[l]){
        if(nxt <= r && nxt != n) break;;
        ret += func(nxt, r);
        if(ret >= mod) ret -= mod;
    }

    for(auto nxt : es[r]){
        if(nxt <= l)break;
        ret += func(l, nxt);
        if(ret>=mod) ret -=mod;
    }
    return ret;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pos[i] >> power[i] >> flag[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = n; j > i; j--){
            ll d = pos[j] - pos[i];
            if(power[i] >= d){
                se[i].push_back(j);
            }
            if(flag[j] && (flag[i] || i == 1) && power[j] >= d){
                es[i].push_back(j);
            }
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << func(1,1) << '\n';
    


    
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}