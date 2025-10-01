#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, m, k;
string str;
ll sum[3030][3030];
ll arr[3030][3030];
ll r[3030][3030];
ll f[3030][3030];

void solve() {
    cin >> n;
    ll q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];   
        }
    }
    cin >> q;
    while(q--){
        ll val;
        cin >> a >> b >> c >> d >> val;
        sum[a][c] += val;
        sum[a][d+1] -= val;
        sum[b+1][c] -= val;
        sum[b+1][d+1] += val;
    }
    for(int i = 1; i <= 2020; i++){
        for(int j = 1; j <= 2020 ;j++){
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }  
    ll cur = 1;
    for(int i = 1; i <= n; i++){
        cur = i;
        for(int j = 1; j <= n; j++){
            r[j][i] = cur++;
        }
    }

    cur = 1;
    for(int i = n; i >= 1; i--){
        ll tmp = cur++;
        for(int j = 1; j <= n; j++){
            f[j][i] = tmp++; 
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] += sum[r[i][j]][f[i][j]];
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}