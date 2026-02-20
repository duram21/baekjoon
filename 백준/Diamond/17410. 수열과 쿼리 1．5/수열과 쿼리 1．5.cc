#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = int;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, x, y;
string str;
ll arr[101010];
vector<ll>v[1010];
ll sqrtN;


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sqrtN = sqrt(n);
    sqrtN = 1500;

    for(int i = 1; i <= n; i++){
        v[i/sqrtN].push_back(arr[i]);
    }
    for(int i = 0; i <= n / sqrtN; i++){
        sort(v[i].begin(), v[i].end());
    }

    cin >> q;
    while(q--){
        cin >> a;
        if(a == 2){
            cin >> b >> c >> k;
            ll ans = 0;
            ll l = b;
            ll r = c;

            ll tmp = (b / sqrtN + 1) * sqrtN - 1;
            while(l <= r && l <= tmp){
                if(arr[l] > k){
                    ans++;
                }
                l++;
            }
            tmp = c / sqrtN *sqrtN;
            while(l <= r && r >= tmp){
                if(arr[r] > k){
                    ans++;
                }
                r--;
            }
            

            while(l <= r){
                ll sz = v[l/sqrtN].size();
                ll p = l/sqrtN;
                ll idx = upper_bound(v[p].begin(), v[p].end(), k) - v[p].begin();
                ans += sz - idx;
                l += sqrtN;
            }
            cout << ans << '\n';

        }
        else{
            cin >> b >> c;
            ll idx = b / sqrtN;
            ll bef = arr[b];
            ll pos = lower_bound(v[idx].begin(), v[idx].end(), bef) - v[idx].begin();
            v[idx].erase(v[idx].begin() + pos);
            pos = upper_bound(v[idx].begin(), v[idx].end(), c) - v[idx].begin();
            arr[b] = c;
            v[idx].insert(v[idx].begin() + pos, c);
        }
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