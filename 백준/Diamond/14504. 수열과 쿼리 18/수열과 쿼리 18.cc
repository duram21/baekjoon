#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, x, y;
string str;
ll arr[101010];
vector<ll>v[101010];
ll sqrtN;


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sqrtN = sqrt(n);

    for(int i = 1; i <= n; i++){
        v[i/sqrtN].push_back(arr[i]);
    }
    for(int i = 0; i <= n / sqrtN; i++){
        sort(v[i].begin(), v[i].end());
    }

    cin >> q;
    while(q--){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> k;
            ll ans = 0;
            ll l = b;
            ll r = c;

            while(l % sqrtN != 0 && l <= r){
                if(arr[l] > k){
                    ans++;
                }
                l++;
            }
            while((r + 1) % sqrtN != 0 && l <= r){
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
            v[idx].clear();
            ll l = idx * sqrtN;
            ll r = l + sqrtN;
            arr[b] =c;
            for(int i = l ; i < r; i++){
                v[idx].push_back(arr[i]);
            }
            sort(v[idx].begin(), v[idx].end());
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