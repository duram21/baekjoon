#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y, q;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    if (x1 >= x3 && x2 <= x4) {
        if (y3 < y2 && y2 < y4) y2 = y3;
        if (y1 < y4 && y3 < y1) y1 = y4;
    }
    if (y3 <= y1 && y2 <= y4) {
        if (x3 < x2 && x2 < x4) x2 = x3;
        if (x1 < x4 && x3 < x1) x1 = x4;
    }
    cout << (x2 - x1) * (y2 - y1) << '\n';
    return 0;
}