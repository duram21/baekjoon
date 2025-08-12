#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, m, x, k;
string str;
map<ll, ll>mp;

void solve() {
    cin >> n >> k;
    char cmd;
    ll cur = 0;
    for(int i = 1; i <= n; i++){
        cin >> a >> cmd;
        if(cmd == 'L'){
            ll to = cur - a;
            mp[to]++;
            mp[cur]--;
            cur = to;
        }
        else{
            ll to = cur + a;
            mp[cur]++;
            mp[to]--;
            cur = to;
        }
    }
    ll ans = 0;
    ll bef = -1e18;
    ll cnt = 0;
    for(auto cur : mp){
        if(bef == -1e18){
            bef = cur.first;
            cnt += cur.second;
            continue;
        }
        if(cnt >= k){
            ans += cur.first - bef;
        }
        cnt += cur.second;
        bef= cur.first;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}     