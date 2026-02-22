#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, m, k;
ll arr[100];
ll cost[100];
ll sum;

void func(vector<ll>a, vector<ll>b, vector<pair<ll,ll>>& v){
    ll len = a.size();

    for(int i = 0 ; i < (1 << len); i++){
        ll cur = 0;
        ll val = 0;
        for(int j = 0; j < len ;j++){
            if(i & (1 << j)){
                cur += a[j];
                val += b[j];
            }
        }
        v.push_back({val, cur});
    }
    
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<= n; i++){
        cin >> cost[i];
    }
    cin >> k;
    cin >> m;
    for(int i = 0 ;i < m; i++){
        cin >> a;
        sum += arr[a + 1];
    }


    vector<ll>v1, c1;
    vector<ll>v2, c2;
    for(int i = 1; i <= n /2 ; i++){
        v1.push_back(arr[i]);
        c1.push_back(cost[i]);
    }
    for(int j = n / 2 + 1; j <= n; j++){
        v2.push_back(arr[j]);
        c2.push_back(cost[j]);
    }
    vector<pair<ll, ll>>A, B;
    func(v1, c1, A);
    func(v2, c2, B);
    ll ans = 1e12 ;
    sort(B.begin(), B.end());
    for(int i = B.size() - 2; i >= 0; i--){
        B[i].second = min(B[i].second, B[i+1].second);
    }
    for(auto a : A){
        ll val = k - a.first;
        ll idx = lower_bound(B.begin(), B.end(), make_pair(val, (ll)-1)) - B.begin();
        if(idx < B.size() ){
            ll cur = B[idx].second + a.second;
            ans = min(ans, max(0LL, cur - sum));
        }
    }
    if(ans == 1e12){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}