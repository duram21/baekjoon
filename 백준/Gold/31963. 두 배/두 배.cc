#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;
ll arr[262626];
ll chk[262626];
vector<ll>v;

ll func(ll x, ll y){
    ll res = 0;
    while(x > y){
        y *= 2;
        res++;
    }
    return res;
}

ll func2(ll x, ll y){
    ll res = 0;
    while(x >= y * 2){
        y *= 2;
        res++;
    }
    return res;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    ll cur = 1;
    ll ans = 0;
    for(int i = 2; i <= n; i++){
        if(arr[i-1] >= arr[i]) {
            a = func(arr[i-1], arr[i]);
            chk[i]= a + chk[i-1];
        }
        else{
            a = func2(arr[i], arr[i-1]);
            chk[i] = max((ll)0, chk[i-1] - a);
        }
            ans += chk[i];
        //cout << i << ' ' << chk[i] << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}