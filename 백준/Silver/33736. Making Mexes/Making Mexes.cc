#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
 
ll n, a, b, c, m, k, q;
string str;
ll arr[202020];
ll cnt[202020];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    vector<pair<ll,ll>>v;
    for(int i = 0; i <= n; i++){
        if(cnt[i]){
            v.push_back({i, cnt[i]});
        }
    }
    ll sum = 0;
    for(int i = 0; i <= n; i++){
        cout << max(cnt[i], sum) << '\n';
        if(!cnt[i]){
            sum++;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
};