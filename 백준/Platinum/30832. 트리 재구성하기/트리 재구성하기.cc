#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, k, m, q;
string str;
vector<ll>A[1010];
vector<ll>B[1010];
vector<tuple<ll,ll,ll>>ans1;
vector<tuple<ll,ll,ll>>ans2;

void dfs(ll x, ll par){
    for(auto nxt : A[x]){
        if(nxt == par) continue;
        if(x != 1) ans1.push_back({nxt, x, 1});
        dfs(nxt, x);
    } 
}

void dfs2(ll x, ll par){
    for(auto nxt : B[x]){
        if(nxt == par) continue;
        if(x != 1)ans2.push_back({nxt, x, 1});
        dfs2(nxt, x);
    } 
}



void solve() {
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        B[a].push_back(b);
        B[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    
    cout << ans1.size() + ans2.size()  << '\n';
    for(auto [a, b, c] : ans1){
        cout << a<< ' ' << b << ' ' << c << '\n';
    }
    reverse(ans2.begin(), ans2.end());
    for(auto [ a, b, c] : ans2){
        cout <<  a << ' ' << c << ' ' << b << '\n';
    }


}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}