#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e, q;
ll sum[202020];
ll arr[202020];

void solve() {
    cin >> n ;
    vector<ll>v;
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());

    for(int i = 1; i <= n; i++){
        sum[i] = v[i-1] + sum[i-1];
        tot += i * v[i-1];
    }
    v.push_back(1e12);
    cin >> q;
    while(q--){
        cin >> a >> b;
        ll c = arr[a];
        // new
        ll nw = lower_bound(v.begin(), v.end(), b) - v.begin();
        // origin
        ll org = lower_bound(v.begin(), v.end(), c) - v.begin();
        nw -= (c < b);
        ll ans = tot;
        nw++;
        org++;
        if(org <= nw){
            ans -= org * v[org - 1];
            ans -= max(0LL, sum[nw ] - sum[org]);    
            ans += nw * b;
        }

        else{
            ans -= org * v[org - 1];
            ans += max(0LL, sum[org -1] - sum[nw - 1]);
            ans += nw * b;
        }
        cout << ans << '\n';

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}