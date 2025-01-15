#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b, a, c, x, y;
ll arr[202];
ll nxt[202];
bool visited[202];
ll deg[202];

void dfs(ll x) {
    visited[x] = 1;
    if (visited[nxt[x]]) return;
    dfs(nxt[x]);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            nxt[i] = 2;
            deg[2]++;
        }
        else if (i == n) {
            nxt[i] = n - 1;
            deg[n - 1]++;
        }
        else {
            if (arr[i] - arr[i - 1] == arr[i + 1] - arr[i]) {
                nxt[i] = i - 1;
                deg[i - 1]++;
            }
            else if (arr[i] - arr[i - 1] > arr[i + 1] - arr[i]) {
                nxt[i] = i + 1;
                deg[i + 1]++;
            }
            else {
                nxt[i] = i - 1;
                deg[i - 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            ans++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}