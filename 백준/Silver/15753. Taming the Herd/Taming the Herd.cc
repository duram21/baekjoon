#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y;
ll  arr[303];
ll chk[303];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if (arr[1] > 0) {
        cout << -1 << '\n';
        return 0;
    }
    arr[1] = 0;
    bool flag = 1;
    ll mn = 1e9;
    for (int i = n; i >= 1; i--) {
        if (arr[i] == -1) continue;
        ll d = arr[i];
        if (i - d > mn) {
            flag = 0;
            cout << -1 << '\n';
            return 0;
        }
        chk[i - d] = 1;
        mn = min(mn, i - d);
    }
    ll cnt1 = 0;
    ll cnt2 = 0;
    if (arr[n] < 0) chk[n] = 2, cnt2++;
    for (int i = n; i >= 1; i--) {
        if (chk[i] == 1) cnt1++;
        if (chk[i] && arr[i - 1] == -1) {
            cnt2++;
            chk[i-1] = 2;
        }
    }
    cout << cnt1 << ' ' << cnt1 + cnt2 << '\n';
    return 0;
}