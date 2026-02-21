#include <bits/stdc++.h>

using namespace std;
using ll = int;
#define all(v) v.begin(), v.end()

ll n, a, b, c;
string str;
ll A[3030];
ll B[3030];
ll dp[3030];
ll mn1[3030];
ll mn2[3020];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];
    for(int i = 1; i <= n; i++){
        dp[i]= 1e12;
        mn1[i] = 1e12;
        mn2[i] = 1e12;
    }
    
    for(int i =1; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        ll mna = A[i];
        ll mnb = B[i];
        ll idxa = i;
        ll idxb = i;
        for(int j = i; j >= 1;j --){
            if(A[j] < mna){
                mna = A[j];
                idxa = j;
            }
            if(B[j] < mnb){
                mnb = B[j];
                idxb = j;
            }
            if(idxa == idxb){
                dp[i]= min(dp[i], dp[j-1] + 1);
            }
        }
    }

    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    for(int i = 1 ; i <= tc; i++){
        solve();
    }
}