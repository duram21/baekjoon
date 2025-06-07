#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

int n, a, b, c, m, l, q, d;
string str;
int cnt[1501];

void solve() {
    cin >> n >> m;
    vector<pair<int, int>>v;
    for(int i = 1; i <= m; i++){
        v.push_back({0, i});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> str;
        vector<pair<int, int>>v2;
        vector<int>zero;
        vector<int>idx;
        for(int j = 1 ; j <= m; j++){
            a = v[j-1].first; // length
            b = v[j-1].second; // idx

            if(str[b-1] == '0'){
                cnt[b] = 0;
                zero.push_back(b);
            }
            else{
                cnt[b]++;
                idx.push_back(b);
            }
        }
        for(auto a : idx){
            v2.push_back({cnt[a], a});
        }
        for(auto a : zero){
            v2.push_back({0, a});
        }
        for(int i = 0 ; i < m; i++){
            ans = max(ans, v2[i].first * (i + 1));
        }
        v = v2;
    }
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
    return 0;
}