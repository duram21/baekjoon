#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, s;
string str;
ll dp[55][55];

ll func(ll n, ll sum){
    if(!n){
        if(sum ) return 0;
        else return 1;
    }
    ll &ret = dp[n][sum];
    if(ret != -1) return ret;

    ret = func(n - 1, sum + 1);
    if(sum) ret += func(n - 1, sum -1);
    return ret;
}

void trace(ll n, ll sum, ll k){
    if(!n) return;
    if(k >= func(n - 1, sum + 1)){
        cout << ')';
        trace(n - 1, sum - 1, k - func(n-1, sum + 1));
    }
    else{
        cout << '(';
        trace(n - 1, sum + 1, k);
    }
}

void solve() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    ll val = func(n, 0);
    if(k >= val) cout << -1 << '\n';
    else{
        trace(n, 0, k);
    }
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}