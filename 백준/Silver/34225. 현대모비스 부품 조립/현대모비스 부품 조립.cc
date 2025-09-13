#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, q;
string str;


void solve() {
    cin >> n;
    vector<pair<ll,ll>>v;
    for(int i =1 ; i <= n; i++){
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.rbegin(), v.rend());
    vector<ll>ans;
    ll cur = v[0].first * 3;
    ans.push_back(v[0].second);
    ll idx = 0;
    ll sum = v[0].first;
    for(int i = 1; i < n; i++){
        sum += v[i].first;
        ll tmp = sum + v[0].first + v[i].first;
        if(tmp > cur){
            cur = tmp;
            idx = i;
        }
    }
    for(int i = 1; i <= idx; i++){
        ans.push_back(v[i].second);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for(auto aa : ans){
        cout << aa << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}