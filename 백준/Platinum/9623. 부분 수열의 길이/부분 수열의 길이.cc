#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, k, a, b, x;
string str;
ll arr[505050];
ll sum[505050];


void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    vector<pair<ll,ll>>v;
    ll ans = 1e12;
    v.push_back({0,0});
    for(int i = 1; i <= n; i++){
        ll cur = sum[i] - x;
        ll idx = upper_bound(v.begin(), v.end(), make_pair(cur, (ll)1e12)) - v.begin();
        if(idx){
            ans = min(ans,  i - v[idx-1].second);
        }
        while(v.size() && v.back().first >= sum[i]){
            v.pop_back();
        }
        v.push_back({sum[i], i});
    }  
    if(ans == 1e12) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}