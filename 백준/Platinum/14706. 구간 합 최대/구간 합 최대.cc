#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k , q;
string str;


void solve() {
  cin >> n >> m;
  vector<ll>L(m);
  vector<ll>S(m);
  for(int i = 0 ; i <  m; i++){
    cin >> L[i] >> S[i];
  }
  ll INF = 4e18;
  vector<ll>dp(n + 1, INF);
  dp[0] = 0;
  for(int k = 1; k <= n; k++){
    ll cur = INF;
    for(int i = 0 ; i < m; i++){
      ll prev = max(0LL, k - L[i]);
      cur = min(cur, dp[prev] + S[i]);
    }
    dp[k] = cur;
  }
  for(int i = 1; i <= n; i++){
    cout << dp[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll tc=  1;
  // cin >> tc;
  for(int i = 1; i <= tc;i++){
    solve();
  }
}