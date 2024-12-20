#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, a, b, c, k, tc, l;
queue<pair<ll,ll>>q;
ll arr[303030];
set<ll>s;

void solve(){
    cin >> l >> n >> k;
    for(int i = 1; i <= n;i ++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        q.push({arr[i], 0});
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] -1 >= 0) q.push({arr[i] - 1, -1});
        if(arr[i] + 1 <= l) q.push({arr[i] + 1, 1});
    }
    while(q.size() && k){
        a = q.front().first;
        b = q.front().second;
        q.pop();
        if(s.find(a) != s.end()) continue;
        s.insert(a);
        k--;
        if(b == 0){
            cout << 0 << '\n';
            continue;
        }
        else if(b > 0){
            cout << b << '\n';
            if(a + 1 <= l && s.find(a +1) == s.end()){
                q.push({a+1, b+1});
            }
        }
        else{
            cout << abs(b) <<'\n';
            if(a - 1 >= 0 && s.find(a-1) == s.end()){
                q.push({a-1, b-1});
            }
        }
    }
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    tc = 1;
    while(tc--){
        solve();
    }
}