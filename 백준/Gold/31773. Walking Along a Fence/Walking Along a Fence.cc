#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
ll dist[1010][1010];
ll A[202020];
ll B[202020];

void solve() {
    cin >> n >> p;
    ll cur = 0;
    d = 0;
    for(int i = 1; i <= p; i++){
        cin >> A[i] >> B[i];
    }
    A[p + 1] = A[1];
    B[p + 1] = B[1];
    for(int i = 1; i <= p; i++){
        ll x1 = A[i]; ll y1 = B[i];
        ll x2 = A[i+1]; ll y2 = B[i+1];
      
        ll dx = x2 - x1;
        ll dy= y2 - y1;

        ll D = abs(dx) + abs(dy);
        dx /= D;
        dy /= D;
        for(int i = 0; i < D; i++){
            dist[x1][y1] = d++;
            x1 += dx;
            y1 += dy;
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c >> e;
        ll res = abs(dist[a][b] - dist[c][e]);
        res = min(res, d - res);
        cout << res << '\n';
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