#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m;

void solve() {
  cin >> n >> m;
  vector<ll>tc(m + 1, 0 );
  for(int i = 1;i <= m ;i++){
    cin >> tc[i];
  }
  ll mx = -1;
  ll ans = 1;
  for(int i = 1; i <= n; i++){
    ll cnt = 0;
    for(int j = 1; j <= m; j++){
      cin >> a;
      if(a == tc[j]) cnt++;
    }
    if(cnt > mx){
      mx = cnt;
      ans = i;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}