#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, d, a, b, c, tc,  k, q;
ll arr[202020];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    bool flag = 1;
    for (int i = 2; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            cout << "NO\n";
            return;
        }
        arr[i] -= arr[i - 1];
    }
    if(arr[n] - arr[n-1] == -1 || arr[n] - arr[n-1] == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(void) { 
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;

    cin >> tc;
    while (tc--) {
        solve();
    }
}