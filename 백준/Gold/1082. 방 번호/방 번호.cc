#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, m, k;
string str;
ll cost[55];
vector<char>dp[55];

string func(vector<char>v) {
    if (v.size() == 0) return "";
    sort(v.rbegin(), v.rend());
    string cur = "";
    for (auto a : v) {
        cur += a;
    }
    return cur;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cin >> m;

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j < n; j++) {
            if (i + cost[j] > m ) {
                continue;
            }

            vector<char>tmp = dp[i];
            tmp.push_back((char)('0' + j));
            string cur = func(dp[i + cost[j]]);
            string nxt = func(tmp);
            bool flag = 0;
            for(auto a : cur){
                if(a != '0'){
                    flag = 1;
                }
            }
            if(!flag && cur.size()) cur = "0";
            flag = 0;
            for(auto a : nxt){
                if(a != '0'){
                    flag = 1;
                }
            }
            if(!flag && nxt.size()) nxt = "0";
            //cout << cur << ' ' << nxt << '\n';
            if (nxt.length() > cur.length()) {
                dp[i + cost[j]] = tmp;
            }
            else if(nxt.length() == cur.length()){
                if(nxt > cur){
                    dp[i + cost[j]] = tmp;
                }
            }
        }
    }
    string ans = "";
    for (int i = m; i >= 0; i--) {
        //cout << i << '\n';
        string cur = func(dp[i]);
        bool flag= 0;
        for (auto a : cur) {
            if (a != '0')
            {
                flag = 1;
            }
        }
        if (!flag && cur.size())
            cur = "0";
        if(ans.length() < cur.length()){
            ans = cur;
        }
        else if(ans.length() == cur.length()){
            if(cur > ans){
                ans = cur;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();
}