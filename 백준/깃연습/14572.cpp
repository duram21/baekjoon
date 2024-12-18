#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, d, m, k, tc;
vector<ll>v[101010];
pair<ll,ll> arr[101010];
ll cnt[31];

void solve(){
    cin >> n >> k >> d;
    for(int i = 1; i <= n; i++){
        cin >> m >> a;
        arr[i] = {a, i};
        while(m--){
            cin >> a;
            v[i].push_back(a);
        }
    }
    sort(arr+1, arr+1+n);
    ll ans = 0;
    ll mn = arr[1].first;
    ll l = 1;
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i].first - mn > d){
            while(arr[i].first - arr[l].first > d){
                ll cur = arr[l].second;
                for(ll nxt : v[cur]){
                    cnt[nxt]--;
                }
                tot--;
                l++;
                mn = arr[l].first;
            }
        }
        if(arr[i].first - mn <= d){
            ll cur = arr[i].second;
            for(ll nxt : v[cur]){
                cnt[nxt]++;
            }
            tot++;
        }
        ll fval = 0;
        ll sval = 0;
        for(int i = 1; i <= k; i++){
            if(cnt[i]) fval++;
            if(cnt[i] == tot) sval++;
        }
        ans = max(ans, (fval - sval) * tot);
    }
    cout << ans <<'\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}