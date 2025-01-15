#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y;
map<ll, ll>m;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ll ans = 0;
    ll val = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        val += abs(b - a);
        if (abs(a) > abs(a - b)) continue;
        m[b] += 2;
        if (a < b && a < 0) {
            m[0]--;
            m[2 * b]--;
        }
        if (a < b && a >= 0) {
            m[2 * b - 2 * a]--; 
            m[2 * a]--; 
        }
		if (a >= b && a < 0) { 
            m[2 * b - 2 * a]--; 
            m[2 * a]--; 
        }
		if (a >= b && a >= 0) { 
            m[0]--; 
            m[2 * b]--; 
        }
    }
    ans = val;
    ll bef = -2000000000;
    ll diff = 0;
    for (auto mm : m) {
        ll cur_y = mm.first;
        ll cur_diff = mm.second;
        val += diff * (cur_y - bef);
        bef = cur_y;
        diff += cur_diff;
        ans = min(ans, val);
        //cout << val << '\n';
    }
    cout << ans << '\n';

    return 0;
}