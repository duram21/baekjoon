#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c;
ll arr[101010];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll cnt = -1;
    ll ans = 0;
    for (int i = 0; i <= 30; i++) {
        b = (1 << i) - 1;
        priority_queue<ll>pq;
        for (int j = 1; j <= n; j++) {
            pq.push(-(b & arr[j]));
        }
        ll cur = 0;
        while (pq.size()) {
            a = -pq.top();
            pq.pop();
            if (a > cur) break;
            if (a == cur) {
                cur++;
            }
        }
        cur--;
        if (cnt < cur) {
            ans = b;
            cnt = cur;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}