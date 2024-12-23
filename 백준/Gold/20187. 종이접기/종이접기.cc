#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, tc;
ll arr[300][300][5][5];
char command;
vector<pair<ll,ll>>v[300][300];

void updown(ll x, ll y) {
    swap(arr[x][y][0][1], arr[x][y][1][1]);
    swap(arr[x][y][1][0], arr[x][y][0][0]);
}

void leftright(ll x, ll y) {
    swap(arr[x][y][0][0], arr[x][y][0][1]);
    swap(arr[x][y][1][1], arr[x][y][1][0]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 1; j <= (1 << n); j++) {
            arr[i][j][0][0] = 0;
            arr[i][j][0][1] = 1;
            arr[i][j][1][0] = 2;
            arr[i][j][1][1] = 3;
            v[i][j].push_back({ i, j });
        }
    }
    ll rst = 1;
    ll ren = (1 << n);
    ll cst = 1;
    ll cen = (1 << n);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> command;
        if (command == 'U') {
            ll mid = (rst + ren) >> 1;
            for (int j = mid + 1; j <= ren; j++) {
                for (int k = cst; k <= cen; k++) {
                    for (auto nxt : v[j][k]) {
                        v[mid - (j - mid -1)][k].push_back(nxt);
                        updown(nxt.first, nxt.second);
                    }
                    v[j][k].clear();
                }
            }
            ren = mid;
        }
        if (command == 'D') {
            ll mid = (rst + ren) >> 1;
            for (int j = rst; j <= mid; j++) {
                for (int k = cst; k <= cen; k++) {
                    for (auto nxt : v[j][k]) {
                        v[ren - (j - rst)][k].push_back(nxt);
                        updown(nxt.first, nxt.second);
                    }
                    v[j][k].clear();
                }
            }
            rst = mid + 1;
        }
        if (command == 'R') {
            ll mid = (cst + cen) >> 1;
            for (int j = rst; j <= ren; j++) {
                for (int k = cst; k <= mid; k++) {
                    for (auto nxt : v[j][k]) {
                        v[j][cen - (k - cst)].push_back(nxt);
						leftright(nxt.first, nxt.second);
                    }
                    v[j][k].clear();
                }
            }
            cst = mid + 1;
        }
        if (command == 'L') {
            ll mid = (cst + cen) >> 1;
            for (int j = rst; j <= ren; j++) {
                for (int k = mid + 1; k <= cen; k++) {
                    for (auto nxt : v[j][k]) {
                        v[j][mid - (k - mid - 1)].push_back(nxt);
                        leftright(nxt.first, nxt.second);

                    }
                    v[j][k].clear();
                }
            }
            cen = mid;
        }
    }
    cin >> c;
    a = c / 2;
    b = c % 2;
    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 1; j <= (1 << n); j++) {
            cout << arr[i][j][a][b] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
}