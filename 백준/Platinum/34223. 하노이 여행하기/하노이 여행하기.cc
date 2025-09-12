#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, q;
string str;

ll gcd(ll x, ll y){
    if(!y) return x;
    return gcd(y, x%y);
}


void solve() {
    cin >> n;
    if (n == 2) {
        cout << 2 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        return;
    }
    if (n == 3){
        cout << 2 << ' ' << 3 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        return;
    }
    if (n == 4){
        cout <<  2 << ' ' << 3 << ' ' << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 4 << '\n';
        return;
    }

    ll idx = 0;
    for(int i = n / 2; i >= 1; i--){
        ll tmp = n - i;
        if(gcd(i, tmp) == 1){
            idx = i;
            break;
        }
    }
    ll idx2 = n - idx;
    bool flag = 0;
    if(n % 2 == 0){
        ll tmp = n - 1;
        if( idx * idx2 < (tmp / 2) * ( (tmp / 2) + 1)){
            idx = tmp / 2;
            flag = 1;
        }
    }
    if(flag){
        n--;
    }

    vector<ll>v(n + 1);
    for(int i = 1; i < idx; i++){
        v[i] = i + 1;
    }
    v[idx] = 1;

    for(int i = idx + 1; i < n; i++){
        v[i] = i + 1;
    }
    v[n] = idx + 1;
    if(flag){
        v[n+1] = idx + 1;
        n++;
    }

    for(int i = 1; i <= n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
}