#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, d, f, m, k, p, e;
ll M[1010];
bool visited[1010];
ll ans[1010];
map<ll,ll>mp;
set<ll>s;

void solve() {
    cin >> n >> m >> k;
    bool flag = 0;
    for(int i = 1 ; i <= m; i++){
        cin >> M[i];
        mp[M[i]] = i;
        s.insert(M[i]);
        if(M[i] == 1) flag = 1;
    }
    for(int i = 1; i <= k ; i++){
        cin >> a >> b;
        ans[b] = a;
        if(s.find(a) != s.end()){
            visited[mp[a]] = 1;
        }
    }  
    if(!flag){
        for(int i = 1; i <= m; i++){
            if(!visited[i]) continue;
            ll cur = M[i];
            ll idx = -1;
            for(int j = 1 ; j <= n; j++){
                if(ans[j] == cur){
                    idx = j;
                    break;
                }
            }
    
            for(int j = i-1; j >= 1; j --){
                if(visited[j]) continue;
                visited[j] = 1;
                for(int k = idx ; k >= 1; k --){
                    if(ans[k]) continue;
                    ans[k] = cur;
                    break;
                }
            }
    
        }
        for(int i = 1; i <= n; i++){
            if(!ans[i]){
                cout << i << '\n';
                return;
            }
        }
    }
    else{
        ll idx = 1;
        for(int i = 1; i <= m; i++){
            if(!visited[i]){
                visited[i] = 1;
                while(idx <= n){
                    if(ans[idx++]) continue;
                    ans[idx - 1] = M[i];
                    break;
                }
            }
            else{
                while(idx <= n){
                    if(ans[idx++] == M[i]) break;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(ans[i] == 1){
                cout << i << '\n';
                return;
            }
        }
    }


}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}