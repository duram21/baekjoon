#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
 
ll n, a, b, c, m, k, q, d;
string str;
ll A[202];
ll B[201];
ll C[202];

bool func(ll x){
    ll mn = max(1LL, c - x);
    ll mx = min(c, c - (x - (m - 1)));
    for(int i = 1; i <= n; i++){
        ll val = c + m - x;
        if(A[i] > B[i]){
            mx = min(mx, (C[i] - B[i] * val) / (A[i] - B[i]));
        }
        else if(A[i] < B[i]){
            mn = max(mn, (B[i] * val - C[i] - 1) / (B[i] - A[i]) + 1);
        }
        else if (A[i] == B[i]){
            if(A[i] * val> C[i] ) return false;
        }
    }
    return mn <= mx;
}

void solve() {
    cin >> n >> c >> m;
    for(int i = 1; i <= n; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    ll l = 0;
    ll r = c + m - 2;

    while( l <= r){
        ll mid = (l + r)  >> 1;
        if(func(mid)){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << l << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
};