#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k , q;
string str;

void solve() {
  cin >> n;
  ll a = (n - 2 ) / 2;
  ll b = n - 2 - a;
  // cout << a << ' ' << b << '\n';
  cout << 2 * a * b << '\n';
  cout << 1 << ' ' << 2 << '\n';
  
  for(int i = 3; i < 3 + a; i++){
    cout << 2 << ' ' << i << '\n';
  }
  for(int i = 3 + a; i <= n; i++){
    cout << 1 << ' ' << i << '\n';
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