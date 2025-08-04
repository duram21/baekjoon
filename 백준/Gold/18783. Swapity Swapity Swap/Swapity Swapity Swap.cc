#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m, x;
string str;
ll sparse[101010][31];
ll arr[101010];
ll bef[101010];
ll cur[101010];

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
        bef[i] = arr[i];
    }

    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        while( a < b){
            swap(arr[a] , arr[b]);
            a++;
            b--;
        }
    }

    for(int i = 1; i <= n; i++){
        sparse[arr[i]][0] = i;
    }

    for(int j = 1; j < 30; j++){
        for(int i = 1; i <= n; i++){
            sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }

    for(int j = 30; j >= 0; j--){
        if(((1 << j) & k) == 0) continue;

        for(int i = 1; i <= n; i++){
            cur[sparse[i][j]] = bef[i];
        }
        for(int i = 1;i  <= n; i++){
            bef[i] = cur[i];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << cur[i] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}     