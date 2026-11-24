#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
string S;
ll n, m, a, b, c;
vector<pair<ll, pair<ll,ll>>>v;
map<ll,ll>mp;
ll mod = 998244353;

void solve() {
  cin >> n >> m;
  vector<ll>v( n+ 1);
  for(int i = 1; i <= n; i++){
    cin >> v[i];
  }
  vector<ll>mx(n + 2, -1e18);
  for(int i = n;  i >= 1; i --){
    mx[i] = max(mx[i + 1], v[i]);
  }

  ll ans = - 1e18;
  for(int i =1; i <= m + 1; i++){
    ans = max(ans, mx[n - m + i - 1] - v[i]);
  }
  cout << ans << '\n';
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