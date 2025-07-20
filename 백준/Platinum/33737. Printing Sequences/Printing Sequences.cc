#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
 
ll n, a, b, c, m, k, q;
string str;
ll arr[110];

bool chk1(ll l, ll r){
    for(int i = l  + 1; i <= r; i++){
        if(arr[i] != arr[i-1]) return false;
    }
    return true;
}

bool chk2(ll l, ll r){
    ll cnt = 1;
    vector<pair<ll,ll>>v;

    for(int i = l + 1; i <= r; i++){
        if(arr[i] != arr[i-1]){
            v.push_back({arr[i-1],cnt});
            cnt = 1;
        }
        else cnt++;
    }
    v.push_back({arr[r], cnt});
    if(v.size() <= 2) return true;
    if( v.size() % 2 == 0){
        for(int i = 0 ; i + 2 < v.size(); i++){
            if(v[i] != v[i+2]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool chk3(ll l, ll r){
    for(int len = 1; len <= r -l + 1; len++){
        if(( r - l + 1 ) % len) continue;

        bool flag= 1;
        for(int i = l; i + len <= r; i++){
            if(arr[i] != arr[i+len]){
                flag = 0;
                break;
            }
        }
        if(!flag ) continue;

        for(int i = l; i <= l + len; i++){
            if(chk2(l, i) && chk1(i + 1, l + len - 1)){
                return true;
            }
            if(chk1(l, i) && chk2(i + 1, l + len - 1)){
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    if(k == 1){
        bool ret = chk1(1, n);
        if(ret) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    if(k == 2){
        bool ret = chk2(1, n);
        if(ret) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    if(k == 3){
        bool ret = chk3(1, n);
        if(ret) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();
};