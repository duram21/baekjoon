#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
string str;
ll arr[202020];


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ll ans = 0;
    ll cnt = 0;
    ll val = arr[1];
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(arr[i] < val){
            ll gap = val - arr[i];
            if(cnt % 2){
                flag = 0;
                break;
            }
            ans += gap * (cnt / 2);
            val = arr[i];
            cnt++;
        }
        else if(arr[i] == val){
            cnt++;
        }
        else if(arr[i] > val){
            ll gap = arr[i] - val;
            if(i < n){
                if(arr[i + 1] < gap){
                    flag = 0;
                    break;
                }
                else{
                    arr[i + 1] -= gap;
                    ans += gap;
                    cnt++;
                }
            }
            else if( i == n){
                flag = 0;
                break;
            }
        }

    }
    if(flag) cout << ans  * 2<< '\n';
    else cout << -1 << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
