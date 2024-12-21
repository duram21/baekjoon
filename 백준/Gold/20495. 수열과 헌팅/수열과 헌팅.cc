#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, q, k, m, x, y;
pair<ll, ll>arr[505050];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<ll>mn;
    vector<ll>mx;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        arr[i] = { a,b };
        mn.push_back(a - b);
        mx.push_back(a + b);
    }
    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    mn.push_back(1e18);
    for (int i = 1; i <= n; i++) {
        a = arr[i].first;
        b = arr[i].second;
        ll l = lower_bound(mx.begin(), mx.end(), a - b) - mx.begin();
        ll r = upper_bound(mn.begin(), mn.end(), a + b) - mn.begin();

        
        cout << l + 1 << ' ' << r << '\n';
    }

}