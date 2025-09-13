#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, m, q;
string str;
vector<ll>v[202020];


void solve() {
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // case 1 한 번에 됨
    for(int i = 1; i <= n ;i++){
        if(v[i].size() >= 3){
            a = v[i][0];
            b = v[i][1];
            c = v[i][2];

            cout << 3 << '\n';
            cout << a << ' ' << b << '\n';
            cout << b << ' ' << c << '\n';
            cout << a << ' ' << c << '\n';
            return;
        }
    }

    // case 2 한 번에 안됨
    for(int i = 1; i <= n; i++){
        if(v[i].size() == 2){
            a = v[i][0];
            b = v[i][1];
            bool flag = 0;
            if(v[a].size() >= 2){
                for(auto nxt : v[a]){
                    if(nxt != i){
                        c = nxt;
                        break;
                    }
                }
            }
            if(v[b].size() >= 2){
                for(auto nxt : v[b]){
                    if(nxt != i){
                        c = nxt;
                        flag =1;
                        break;
                    }
                }
            }
            cout << 3 << '\n';
            if(!flag){
                cout << a << ' ' << b << '\n';
                cout << c << ' ' << b << '\n';
                cout << c << ' ' << i << '\n';
                return;
            }
            else{
                cout << a << ' ' << b << '\n';
                cout << c << ' ' << a << '\n';
                cout << i << ' ' << c << '\n';
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}