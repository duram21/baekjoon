#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll A[1010];
ll B[1010];
ll cnt1[101];
ll cnt2[101];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> B[i];
    }
    ll l = -1;
    ll r = -1;
    vector<ll>ans;
    while(true){
        if(l == n && r == m) break;
        for(int i = 1; i <= 100 ; i++){
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        for(int i = l + 1; i <= n; i++){
            cnt1[A[i]]++;
        }
        for(int i = r + 1; i <= m; i++){
            cnt2[B[i]]++;
        }
        bool flag = 0;
        for(int i = 100; i >= 1; i--){
            if(!cnt1[i] || !cnt2[i]) continue;
            while(true){
                ++l;
                if(A[l] == i) break;
            }   
            while(true){
                ++r;
                if(B[r] == i) break;
            }
            ans.push_back(i);
            flag = 1;
            break;
        }
        if(!flag) break;
    }
    cout << ans.size() << '\n';
    for(auto x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++){
        solve();
    }
}     