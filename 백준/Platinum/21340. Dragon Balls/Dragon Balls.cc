#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c;
string str;
vector<pair<ll,ll>>v;

pair<ll,ll> get_pos(pair<ll, ll>A, pair<ll,ll>B){
    ll x = (A.second - B.second + B.first * B.first - A.first * A.first) / (2*B.first - 2 * A.first);
    ll y = A.second - (x - A.first) * (x - A.first);
    ll l = 0;
    ll r = 1e7;
    ll res = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(mid * mid <= y){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    if(r * r != y){
        return {-1, -1};
    }
    return {x, r};
}

void solve() {
    // get_pos({}, {3, 20});
    cin >> n;
    while(n){
        v.clear();
        bool flag = 0;
        for(int i = 0; i <= n; i++){
            cout << i << ' ' << 0 << endl;
            cin >> a;
            if(!a){
                n--;
                flag = 1;
                break;
            }
            v.push_back({i, a});
        }
        if(flag) continue;

        for(int i = 0 ; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                pair<ll,ll>tmp = get_pos(v[i], v[j]);
                if(tmp.first < 0 || tmp.second < 0 || tmp.first > 1e6 || tmp.second > 1e6) continue;
                cout << tmp.first << ' ' << tmp.second << endl;
                cin >> a;
                if(!a){
                    n--;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    
    //cin >> tc;
    while (tc--) solve();
}