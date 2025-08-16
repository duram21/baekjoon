#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll arr[505050];

void solve() {
    cin >> a >> b >> c >> n;
    if( n <= 30){
        cout << a << '\n';
        return;
    }
    ll gap = n - 30;
    cout << a + (gap + b - 1) / b * c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve();
    }
}     