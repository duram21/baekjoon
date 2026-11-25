#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, k , q;
string str;

void solve() {
  cin >> n;
  vector<ll>A(n + 1, 0);
  vector<ll>B(n + 1, 0);
  for(int i = 1; i <= n; i++){
    cin >> A[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> B[i];
  }
  sort(A.begin() + 1, A.end());
  sort(B.begin() + 1, B.end());
  vector<ll>mxL(n + 2, 0);
  vector<ll>mxR(n + 2, 0);

  for(int i = 1; i <= n; i++){
    ll cur = abs(A[i] - B[i]);
    mxL[i] = max(mxL[i-1], cur);
  }
  for(int i = n; i >= 1; i --) {
    ll cur = abs(A[i] - B[i]);
    if(i == n){
      mxR[i] = cur;
    }
    else{
      mxR[i] = max(mxR[i+1], cur);
    }
  }
  
  vector<ll>ldp(n + 2, 0);
  vector<ll>rdp(n + 2, 0);

  for(int i = n - 1; i >= 1; i--){
    ldp[i] = max(ldp[i], mxR[i + 1]);
    // 현재거랑 i + 1번째랑 연결
    ll cost = abs(B[i] - A[i + 1]);
    ldp[i] = min(ldp[i], max(cost, ldp[i + 1]));
  }
  
  for(int i = 2; i <= n; i++){
    rdp[i] = mxL[i-1];
    // 현재 거랑 i - 1번쨰랑 연결
    ll cost = abs(B[i] - A[i-1]);
    rdp[i] = min(rdp[i], max(cost, rdp[i - 1]));
  }

  ll ans = 1e18;
  ll a = -1;
  for(int i = 1; i <= n; i++){
    if(ans > max(mxL[i - 1], ldp[i])){
      ans = max(mxL[i - 1], ldp[i]);
      a = A[i];
    }
    if(ans > max(mxR[i + 1], rdp[i])){
      ans = max(mxR[i + 1], rdp[i]);
      a = A[i];
    }
  }
  cout << a << '\n';
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