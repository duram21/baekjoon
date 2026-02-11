#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()

ll n, a, b, c, d, m, k, q, x, y;
string str;

void solve() {
    cin >> a >> x >> y;
    if(x < y){
        cout << a << ' ' << 2 << ' ' << x << ' ' << y << '\n';
        return;
    }

    vector<ll>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(x + 1);
    v.push_back(x + 2);
    v.push_back(x + y - 1);

    if(y <= 3) {
        cout << a << ' ' << "NO PATH\n";
        return;
    }

    while(v[3] > 4 && v[5] > x + 3){
        v[3] --;
        v[5]--;
    }

    cout << a << ' ' << 6 << ' ';
    for(auto cur : v){
        cout << cur << ' ';
    }
    cout << '\n';



    // 1 2 3
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}