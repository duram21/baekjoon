#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k , q;
string str;

void solve() {
  cin >> n;
  cout << "YES\n";
  vector<ll>v(n + 1);
  for(int i = 1; i <= n; i++) v[i] = i;
  if(n % 2){
    for(int i = 3; i <= n; i += 4){
      swap(v[i], v[i-1]);
    }
  }
  else{
    for(int i = 2; i <= n; i += 4){
      swap(v[i], v[i-1]);
    }
  }
  for(int i = 1; i <= n; i++){
    cout << v[i] << ' ';
  }
  cout << '\n';

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