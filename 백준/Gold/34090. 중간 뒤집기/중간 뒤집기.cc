#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll arr[505050];
map<ll,ll>mp;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        mp[a]++;
    }
    ll ans = n * (n - 1) / 2;
    for(auto cur : mp){
        ans -= cur.second *(cur.second - 1) / 2;
    }
    cout << ans + 1<< '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve();
    }
}     