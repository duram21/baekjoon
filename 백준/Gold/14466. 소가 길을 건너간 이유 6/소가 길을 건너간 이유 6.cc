#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, d, r;
string str;
ll arr[101][101];
ll dx[] ={-1, 1, 0, 0};
ll dy[] = {0, 0, 1, -1};
bool flag[101][101][101][101];
bool chk[101][101];
bool visited[101][101];

ll bfs(ll x, ll y){
    queue<pair<ll,ll>>q;
    q.push({x, y});
    visited[x][y]= 1;
    ll ret = 0;
    while(q.size()){
        a = q.front().first;
        b = q.front().second;
        q.pop();
        if(chk[a][b]) ret++;

        for(int i = 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if(visited[nx][ny] ) continue;
            if(flag[a][b][nx][ny] || flag[nx][ny][a][b]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k >> r;
    for(int i = 1; i <= r; i++){
        cin >> a >> b >> c >> d;
        flag[a][b][c][d] = 1;
        flag[c][d][a][b] = 1;
    }
    for(int i = 1; i <= k; i++){
        cin >> a >> b;
        chk[a][b] = 1;
    }
    vector<ll>v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j]) continue;
            ll ret = bfs(i, j);
            if(ret) v.push_back(ret);
        }
    }
    if(v.size() <= 1){
        cout << 0 << '\n';
        return;
    }
    ll sum = 0;
    ll ans = 0;
    for(auto a : v){
        ans += sum * a;
        sum += a;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}