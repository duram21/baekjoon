#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k;
string str;

void solve() {
    cin >> n >> k;
    vector<ll>v;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.push_back(a);
    }
    vector<pair<pair<ll, ll>, ll>>query;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        query.push_back({ {b, a }, c });
    }
    sort(v.begin(), v.end());
    sort(all(query));
    vector<pair<pair<ll, ll>, pair<ll, ll>>>v2;
    for (int i = 0; i < n; i++) {
        v2.push_back({ {v[i], 0}, {0, 0} });
    }
    for (int i = 0; i < k; i++) {
        b = query[i].first.first;
        a = query[i].first.second;
        c = query[i].second;

        ll r = upper_bound(v.begin(), v.end(), b) - v.begin();
        ll l = lower_bound(v.begin(), v.end(), a) - v.begin();
        ll gap = r - l;
        v2.push_back({ {a, -1}, {b, gap - c} });
    }
    sort(v2.begin(), v2.end());
    ll ans = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    for (int i = 0; i < v2.size(); i++) {
        a = v2[i].first.first;
        ll flag  = v2[i].first.second;
        ll gap = v2[i].second.second;
        b = v2[i].second.first;
        if (flag == -1) {
            pq.push({ gap + ans, b });
        }
        else {
            while (pq.size() && pq.top().second < a) {
                pq.pop();
            }
            if (!pq.size() || pq.top().first != ans) ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
};