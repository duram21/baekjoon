#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, m, st, en, q, k;
string str;
ll ans;
ll bef = 100000;
ll bef_res;

ll func(ll x) {
    ll gap = bef - x;
    if (bef_res - gap * n == ans) {
        return true;
    }
    return false;
}

void solve() {
    cin >> n;
        
    cout << "? " << 100000 << endl;
    cin >> bef_res;

    ll l = 1;
    ll r = 100000;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        cout << "? " << mid << endl;
        cin >> ans;
        if (func(mid)) {
            r = mid - 1;
            a = mid;
        }
        else l = mid + 1;
    }
    cout << "! " << a << endl;
    cin >> ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;  
    // cin >> tc;
    while (tc--) solve();
}