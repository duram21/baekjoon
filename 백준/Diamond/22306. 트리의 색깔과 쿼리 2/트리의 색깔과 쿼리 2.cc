#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, k, p, e, q, cur;
ll P[101010];
ll C[101010];
map<ll, ll>m[101010];
set<ll>s[101010];
ll num[101010];
ll chk[101010];

void Ins(ll id, ll val) {
    m[id][val]++;
}

void Del(ll id, ll val) {
    if (!--m[id][val]) {
        m[id].erase(val);
    }
}

void func(ll x, ll y) {
    s[x].erase(y);
    s[y].erase(x);
    cur++;
    queue<pair<ll, ll>>q[2];
    vector<ll>v[2];
    q[0].push({ x, 0 });
    q[1].push({ y, 0 });
    chk[x] = cur;
    chk[y] = cur;
    while (q[0].size() && q[1].size()) {
        for (int i = 0; i < 2; i++) {
            ll a = q[i].front().first;
            ll b = q[i].front().second;
            q[i].pop();

            v[i].push_back(a);

            auto it = s[a].lower_bound(b);
            if(it == s[a].end()) continue;

            q[i].push({a, *it + 1});

            if(chk[*it] != cur){
                chk[*it] = cur;
                q[i].push({*it, 0});
            }
        }
    }
    auto& node = !q[0].size() ? v[0] : v[1];
    for (auto i : node) {
        Del(num[i], C[i]);
        num[i] = cur;
        Ins(cur, C[i]);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> P[i];
        s[i].insert(P[i]);
        s[P[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        m[0][C[i]]++;
    }
    ll bef = 0;
    for (int i = 0; i < n + q - 1; i++) {
        cin >> a >> b;
        b ^= bef;

        if (a == 1) {
            func(P[b],b);
        }
        else {
            bef = m[num[b]].size();
            cout << bef << '\n';
        }
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