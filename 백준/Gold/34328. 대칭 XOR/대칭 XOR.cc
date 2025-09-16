#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, k, m, q;
string str;
ll arr[505050];



void solve() {
    cin >> n;
    for(int i =1; i <= n; i++){
        arr[i] = i;
    }
    set<ll>s;
    for(int i = 1; i <= n; i++){
        ll tmp = arr[i] ^ arr[n- i + 1];
        s.insert(tmp);
    }
    if(s.size() == 1){
        for(int i = 1; i <= n; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else cout << -1 << '\n';
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