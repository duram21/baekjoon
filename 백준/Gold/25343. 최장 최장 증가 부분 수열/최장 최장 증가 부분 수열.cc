#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll arr[101][101];
ll dp[101][101];


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int ii = i  ; ii <= n; ii ++){
                for(int jj = j ; jj <= n; jj++){
                    if(arr[ii][jj] > arr[i][j]){
                        dp[ii][jj] = max(dp[ii][jj], dp[i][j] + 1);
                    }
                }
            }
        }
    }
    ll ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans + 1<< '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve();
    }
}     