#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

ll n, a, b, c, d, q, m, k;
string str;
set<string>s;
string ans;
set<string>visited;
string abc = "abcdefghijklmnopqrstuvwxyz";

void bfs(string w) {
    queue<string>q;
    q.push(w);
    visited.insert(w);

    while (q.size()) {
        string cur = q.front();
        q.pop();
        
        if (cur.size() > ans.size()) {
            ans = cur;
        }

        ll len = cur.size();
        for (int i = 0; i <= len; i++) {
            string a1 = "";
            for (int j = 0; j < i; j++) {
                a1 += cur[j];
            }
            string a2 = "";
            for (int j = i; j < len; j++) {
                a2 += cur[j];
            }
            for (int j = 0; j < 26; j++) {
                string tmp = a1;
                tmp += abc[j];
                tmp += a2;
                
                if (s.find(tmp) == s.end()) {
                    continue;
                }
                if (visited.find(tmp) == visited.end()) {
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
    }

}


void solve() {
    cin >> n >> str;
    for (int i = 1; i <= n; i++) {
        string st;
        cin >> st;
        s.insert(st);
    }

    bfs(str);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll tc = 1;
    //cin >> tc;
    while (tc--) solve();
}