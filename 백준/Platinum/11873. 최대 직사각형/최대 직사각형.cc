#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q, d;
ll arr[1010][1010];
ll sum[1010][1010];
ll mx[1010][1010];

void solve() {
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i =1 ; i <= n + 2; i++){
        for(int j = 1; j <= m + 2; j++){
            sum[i][j] = 0;
            mx[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= m; j++){
            if(arr[i][j] == 0){
                sum[i][j] = 0;
            }
            else{
                sum[i][j] = sum[i-1][j] + 1;
            }
        }
    }
    for(int i = n ; i >= 1; i --){
        for(int j = 1; j <= m ;j++){
            if(sum[i][j]){
                mx[i][j] = max(sum[i][j], mx[i+1][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        stack<pair<ll,ll>>st;
        for(int j = 1; j <= m; j++){
            ll cur= mx[i][j] - sum[i][j] + 1;
            if(!mx[i][j]) cur = 0;
            ll bef = j;
            while(st.size() && st.top().first > cur){
                a = st.top().first;
                b = st.top().second;
                st.pop();
                bef= b;
                ans = max(ans, (j - b ) * a);
            }
            st.push({cur, bef});
 
        }

        while(st.size()){
            a = st.top().first;
            b = st.top().second;
            st.pop();

            ans = max(ans, (m + 1 - b) * a);
        }
    
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc) {
        cin >> n >> m;
        if(!n && !m) break;
		solve();
	}
}