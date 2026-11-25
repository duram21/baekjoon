#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k , q;
string str;

struct Cow{
  ll u, d;
};

bool op(const Cow a, const Cow b){
  bool ga = (a.u < a. d);
  bool gb = (b.u < b.d) ;
  if(ga != gb) return ga > gb;
  if(ga ) return a.u < b.u;
  return a.d > b.d;
}

void solve() {
  cin >> n;
  vector<Cow>cow(n);
  for(int i = 0 ; i < n; i++){
    cin >> cow[i].u >> cow[i].d ;
  }
  sort(all(cow), op);

  ll ans1 =0 ;
  ll ans2= 0;

  for(auto a : cow){
    ans1 += a.u;
    ans2 = max(ans1, ans2) + a.d;
  }
  cout << ans2 << '\n';
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