#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
string str;


void solve() {
    cin >> n;
    cin >> str;

    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        ll lcnt = 0;
        ll rcnt = 0;
        if(i > 0 && str[i-1] != str[i]){
            lcnt++;
            for(int j = i - 2; j >= 0; j--){
                if(str[j + 1] == str[j]) lcnt++;
                else break;
            }
        }
        if(i < n - 1 && str[i+1] != str[i]){
            rcnt++;
            for(int j = i + 2; j < n; j++){
                if(str[j] == str[j - 1]) rcnt++;
                else break;
            }
        }
        ans += lcnt * rcnt;
        if(lcnt) ans += lcnt - 1;
        if(rcnt) ans += rcnt - 1;
    }
    cout << ans << '\n';

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
