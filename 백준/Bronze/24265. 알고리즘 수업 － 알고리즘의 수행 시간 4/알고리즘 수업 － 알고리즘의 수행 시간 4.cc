#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, l, d, t, q, m;

void solve() {
    cin >> n;
    ll sum = 0;
    for(int i = 1; i < n; i++){
        sum += i;
    }
    cout << sum << '\n';
    cout << 2 << '\n';
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