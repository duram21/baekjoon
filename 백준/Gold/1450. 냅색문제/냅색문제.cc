#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c;
ll arr[100];

void func(vector<ll>a, vector<ll>& v){
    ll len = a.size();

    for(int i = 0 ; i < (1 << len); i++){
        ll cur =0 ;
        for(int j = 0; j < len ;j++){
            if(i & (1 << j)){
                cur += a[j];
            }
        }
        v.push_back(cur);
    }
}

void solve() {
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<ll>v1;
    vector<ll>v2;
    for(int i = 1; i <= n /2 ; i++){
        v1.push_back(arr[i]);
    }
    for(int j = n / 2 + 1; j <= n; j++){
        v2.push_back(arr[j]);
    }
    vector<ll>A, B;
    func(v1, A);
    func(v2, B);
    sort(all(A));
    sort(all(B));
    ll ans = 0 ;
    for(auto a : A){
        ll val = c - a;
        if(val < 0) continue;
        ll idx = upper_bound(all(B), val) - B.begin();
        ans += idx;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}