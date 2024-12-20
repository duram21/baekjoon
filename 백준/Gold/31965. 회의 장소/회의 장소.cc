#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, q, m, k, tc;
ll arr[202020];
ll sum[202020];
ll p[202020];
vector<ll>pos;

ll func(ll l, ll r, ll x){
    return (x - l) * arr[x] - sum[x-1] + (sum[r] - sum[x]) - arr[x] * (r - x);
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        pos.push_back(arr[i]);
    }
    // 피로도
    for(int i = 1; i <= n; i++){
        p[i] = (i-1) * arr[i] - sum[i-1] + (sum[n] - sum[i]) - arr[i] * (n - i);
    }
    while(q--){
        cin >> a >> b;
        ll idx1 = lower_bound(pos.begin(), pos.end(), a) - pos.begin();
        ll idx2 = lower_bound(pos.begin(), pos.end(), b) - pos.begin();
        idx1++;
        idx2++;
        if(pos[idx2-1] != b) idx2--;
        if(idx1 >= idx2){
            cout << 0 << '\n';
            continue;
        } 
        ll nn = idx2 - idx1 + 1;
        ll mid = (idx1 + idx2) / 2;
        ll mnval = func(idx1, idx2, mid);
        ll mxval1 = func(idx1, idx2, idx1);
        ll mxval2 = func(idx1, idx2, idx2);
        cout << max(mxval1, mxval2) - mnval << '\n';

    }
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}