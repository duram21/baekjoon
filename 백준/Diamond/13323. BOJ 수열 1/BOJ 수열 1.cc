#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q;
string str;
ll arr[1010101];


void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    priority_queue<ll>pq;
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!pq.size() || pq.top() + i <= arr[i]){
            pq.push(arr[i] - i);
        }
        else{
            ans += pq.top() + i - arr[i];
            pq.pop();
            pq.push(arr[i] - i );
            pq.push(arr[i] - i);
        }
    }
    cout << ans << '\n';

}   

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}