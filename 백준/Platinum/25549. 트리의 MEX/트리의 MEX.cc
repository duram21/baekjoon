#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, l, d, t, q, m, k;
ll par[201010];
set<ll>s[201010];
vector<ll>v[201010];
ll idx[201010];
ll cnt[201010];
ll ans[201010];

void func(ll x){
    for(auto nxt : v[x]){
        func(nxt);
        ll a = idx[x];
        ll b = idx[nxt];
        if(s[a].size() < s[b].size()){
            swap(a, b);
            idx[x] = a;
        }
        cnt[a] = max(cnt[a], cnt[b]);
        for(auto c : s[b]){
            s[a].insert(c);
        }
    }
    a = idx[x];
    while(s[a].find(cnt[a]) != s[a].end()){
        cnt[a]++;
    }
    ans[x] = cnt[a];
}

void solve() {
    cin >> n;
    ll root = -1;
    for(int i =1; i <= n; i++){
        cin >> par[i];
        idx[i] = i;
        if(par[i] == -1) root = i;
        else v[par[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> a;
        s[i].insert(a);
    }
    func(root);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
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