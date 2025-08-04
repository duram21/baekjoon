#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll bias = 10000;
vector<ll>x[20101];
vector<ll>y[20101];
vector<pair<ll,ll>>v;
ll mod = 1e9 + 7;
map<ll,ll>vx[20202];
map<ll,ll>vy[20202];

void solve() {
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> a >> b;
        a += bias;
        b += bias;
        x[a].push_back(b);
        y[b].push_back(a);
        v.push_back({a, b});
    }
    for(int i = 0; i <= 20000; i++){
        sort(all(x[i])); 
        sort(all(y[i]));
    }

    for(int i = 0 ; i <= 20000; i++){
        ll sum = 0;
        for(auto cur : x[i]){
            sum += cur - x[i][0];
            sum %= mod;
        }
        for(int j = 0 ; j < x[i].size(); j++){
            if(j){
                sum += (x[i][j] - x[i][j-1]) * j % mod;
                sum-= (x[i][j] - x[i][j-1]) * (x[i].size() - j) % mod;
                if(sum < 0) sum += mod;
                sum %= mod;
            }
            vx[i][x[i][j]] = sum;
        }

        sum = 0;
        for(auto cur : y[i]){
            sum += cur - y[i][0];
            sum %= mod;
        }
        for(int j = 0 ; j < y[i].size(); j++){
            if(j){
                sum += (y[i][j] - y[i][j-1]) * j % mod;
                sum-= (y[i][j] - y[i][j-1]) * (y[i].size() - j) % mod;
                if(sum < 0) sum += mod;
                sum %= mod;
            }
            vy[i][y[i][j]] = sum;
        }
    }

    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        a = v[i].first;
        b = v[i].second;

        ans += vx[a][b] * vy[b][a];
        ans %= mod;
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}     