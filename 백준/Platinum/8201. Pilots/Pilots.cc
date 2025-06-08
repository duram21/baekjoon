#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

int n, a, b, c, m, l, d, t;
ll arr[3030303];

void solve() {
    cin >> t >> n;
    deque<ll>inc;
    deque<ll>dec;

    for(int i = 1; i <= n;i++) cin >> arr[i];

    ll idx = 1;
    ll ans = -1;
    for(int i = 1; i <= n ;i++){
        ll cur = arr[i];
        while(inc.size() && arr[inc.back()] >= cur){
            inc.pop_back();
        }
        while(dec.size() && arr[dec.back()] <= cur){
            dec.pop_back();
        }
        inc.push_back(i);
        dec.push_back(i);

        while(true){
            if(arr[dec.front()] - arr[inc.front()] <= t) break;
            if(dec.front() == idx) dec.pop_front();
            if(inc.front() == idx) inc.pop_front();
            idx++;
        }
        ans = max(ans, i - idx + 1);
    }
    cout << ans << '\n';
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