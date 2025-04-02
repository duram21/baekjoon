#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;

const ll NMAX = 10;
ll mod = 1e6 + 3;

ll a, b, n, s, e, t;
string str;
Matrix arr(NMAX*5 + 1, vector<ll>(NMAX * 5 + 1, 0));


Matrix mult(Matrix& A, Matrix& B){
    Matrix tmp(n+1, vector<ll>(n+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 1; k <= n; k++){
                tmp[i][j] += (A[i][k] * B[k][j]) % mod;
            }
            tmp[i][j] %= mod;
        }
    }
    return tmp;
}

Matrix solve(ll n){
    if(n == 1){
        return arr;
    }
    Matrix aa = solve(n/2);
    aa = mult(aa, aa);
    if(n % 2 == 1){
        aa = mult(aa, arr);
    }
    return aa;
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s >> e >> t;
	ll N = 5 * n;
	for(int i = 0 ; i < n; i++){
		for(int j = 1; j <5 ; j++){
			arr[i * 5 + j][i * 5 + j + 1] = 1;
		}
	}
    for(int i = 1; i <= n; i++){
		cin >> str;
        for(int j = 0; j < n; j++){
            if(str[j] == '0') continue;
			ll aa = str[j] - '0' - 1;
			arr[i * 5][(j+1) * 5 - aa] = 1;
        }
    }
	n *= 5;

    Matrix ans = solve(t);
\
    cout << ans[5*(s)][5*(e)] << '\n';
}
