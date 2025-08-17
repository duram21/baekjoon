#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, t, k, m;
string str;
ll arr[505050];
map<ll,ll>mp;

void solve() {
    cin >> n >> k;
    ll sum = 0;
    ll cnt = 0;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(int i = 1; i <= n; i++){
        cin >> a;
        sum += a;
        cnt++;
        pq.push(a);
        while(pq.size() && sum - pq.top() >= k){
            sum -= pq.top();
            pq.pop();
            cnt--;
        }
        if(sum < k) cout << -1 << ' ';
        else cout << cnt << ' ';
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