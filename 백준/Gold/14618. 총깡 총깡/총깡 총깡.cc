#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, st;
string str;
vector<pair<ll, ll>>v[5050];
ll dist[5050];
ll house[5050];

void dijk() {
    priority_queue<pair<ll,ll>>pq;
    pq.push({ 0, st });
    dist[st] = 0;

    while (pq.size()) {
        a = -pq.top().first;
        b = pq.top().second;
        pq.pop();
        
        if (dist[b] < a) continue;

        for (auto nxt : v[b]) {
            ll node = nxt.first;
            ll d = nxt.second;

            if (dist[node] > dist[b] + d) {
                dist[node] = dist[b] + d;
                pq.push({ -dist[node], node });
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    cin >> st;
    cin >> k;
    vector<ll>A;
    vector<ll>B;
    for (int i = 1; i <= k; i++) {
        cin >> a;
        house[a] = 1;
        A.push_back(a);
    }
    for (int i = 1; i <= k; i++) {
        cin >> a;
        house[a] = 2;
        B.push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a, c });
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }
    dijk();
    ll ans = 1e18;
    char cans = ' ';
    for (int i = 1; i <= n; i++) {
        if (st == i) continue;
        if (house[i] == 0) continue;
        if (dist[i] < 1e18) {
            if (dist[i] <= ans) {
                if (dist[i] == ans) {
                    cans = 'A';
                }
                else if (house[i] == 1) {
                    cans = 'A';
                }
                else if (house[i] == 2) {
                    cans = 'B';
                }
                ans = dist[i];
            }
        }
    }
    if (cans == ' ') {
        cout << -1 << '\n';
        return;
    }
    
    cout << cans << '\n';
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}