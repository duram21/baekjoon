#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
char arr[2020][2020];
char ans[2020][2020];
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, 1, -1};

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int j = 1; j <= m; j++){
            arr[i][j] = str[j-1];
            ans[i][j] = 2;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                ll nx = dx[k] + i;
                ll ny = dy[k] + j;
                if(arr[nx][ny] == 'W') arr[nx][ny] = 'B';
                else arr[nx][ny] = 'W';
            }
        }
    }
    

    cout << 1 << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == 'W') cout << 2;
            else cout << 3;
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}     