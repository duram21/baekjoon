#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;

const ll NMAX = 3;
ll mod = 1e9 + 7;

ll a, b, n;
Matrix arr(NMAX + 1, vector<ll>(NMAX + 1, 0));

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}

Matrix mult(Matrix& A, Matrix& B) {
    Matrix tmp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                tmp[i][j] += (A[i][k] * B[k][j]) % mod;
            }
            tmp[i][j] %= mod;
        }
    }
    return tmp;
}

Matrix solve(ll nn) {
    if (nn == 1) {
        return arr;
    }
    Matrix aa = solve(nn / 2);
    aa = mult(aa, aa);
    if (nn % 2 == 1) {
        aa = mult(aa, arr);
    }
    return aa;
}


int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    n = 2;
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[2][1] = 1;
    arr[2][2] = 0;
    a = gcd(a, b);
    if (a == 1) {
        cout << 1 << '\n';
        return 0;
    }
    Matrix ans = solve(a - 1);
    Matrix tmp(3, vector<ll>(3, 0));
    tmp[1][1] = 1;
    tmp[2][1] = 0;
    ans = mult(ans, tmp);
    cout << ans[1][1] % mod << '\n';
}
