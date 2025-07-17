#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k, q;
string str;

void solve() {
    cin >> a >> b >> str;
    if((str.back() - '0') % 2){
        cout << (a ^ b) <<'\n';
    }
    else cout << (a) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
};