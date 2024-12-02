#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, tc, a, b;
ll par[505050];

ll find(ll x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}


void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n;i++) par[i] = i;
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        ll pa = find(a);
        ll pb = find(b);
        if(pa == pb){
            ans = i;
            break;
        }
        else{
            par[pa] = pb;
        }
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
    
}