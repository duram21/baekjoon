#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k, q;
string str;

ll dx[] = {-1, 0, 0, 1};
ll dy[] = {0, 1, -1, 0};
char dir[] = {'U', 'R', 'L', 'D'};
ll tot;
ll arr[1010][1010];
bool usb[1010][1010];

bool pos(ll x, ll y){
    return !(x < 1 || y < 1 || x > n || y > n);
}

bool chk(ll x, ll y){
    if(!pos(x,y)) return false;

    for(int i = 0 ; i < 4; i++){
        if(arr[x][y] != -1 && arr[x][y] != i) continue;

        ll nx = x +dx[i];
        ll ny = y + dy[i];
        if(!pos(nx, ny) || usb[nx][ny]) return true;
    }
    return false;
}

void dfs(ll x, ll y){
    if(!chk(x,y)) return;
    if(usb[x][y]) return;
    usb[x][y] = 1;
    tot++;
    for(int i = 0 ; i < 4; i++){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(!pos(nx, ny)) continue;
        dfs(nx, ny);
    }
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = -1;
        }
    }
    vector<tuple<ll, ll, char>>query;
    for(int i = 1;i <= q; i++){
        char cmd;
        cin >> a >> b >> cmd;
        if(cmd == 'R'){
            arr[a][b] = 1;
        }
        else if(cmd == 'L'){
            arr[a][b] = 2;
        }
        else if(cmd== 'U'){
            arr[a][b] = 0;
        }
        else arr[a][b] = 3;
        query.push_back({a, b, cmd});
    }
    reverse(query.begin(), query.end());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dfs(i, j);
        }
    }
    vector<ll>ans;
    for(auto [a, b, cmd] : query){
        ans.push_back(n*n - tot);
        arr[a][b] = -1;
        dfs(a, b);
    }
    reverse(ans.begin(), ans.end());
    for(auto cur : ans ){
        cout << cur << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
};