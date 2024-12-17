#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, m, k, tc;

void solve(){
    cin >> n;
    ll ans= 0; 
    stack<pair<ll, ll>>st;
    for(int i = 1; i <= n;i++){
        cin >> a;
        ll dist = 0;
        ll cnt = 0;
        while(st.size() && st.top().first < a){
            dist += st.top().second;
            cnt++;
            st.pop();
        }
        ans += i * cnt - dist + cnt;
        if(st.size()){
            ans += i - st.top().second + 1;
        }
        st.push({a, i});
    }
    cout << ans << '\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
    
}