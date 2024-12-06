#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll tc, n, a, b, c, k, m;
vector<pair<ll, ll>>edges[10101];;
ll dist[10101][21];

void func(){
    dist[1][0] = 0;
    priority_queue<pair<ll, pair<ll,ll>>>pq;
    pq.push({0, {1, 0}});
    while(!pq.empty()){
        ll d = -pq.top().first;
        ll cur = pq.top().second.first;
        ll cnt = pq.top().second.second;
        pq.pop();
        if(dist[cur][cnt] < d) continue;
        for(int i = 0 ; i < edges[cur].size(); i++){
            ll nxt = edges[cur][i].first;
            ll cost = edges[cur][i].second;
            ll ndist = cost + d;
            if(dist[nxt][cnt] > ndist){
                dist[nxt][cnt] = ndist;
                pq.push({-ndist,{nxt, cnt}});
            }
            if(cnt < k){
                if(dist[nxt][cnt+1] > d){
                    dist[nxt][cnt+1] = d;
                    pq.push({-d, {nxt, cnt+1}});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= k;j ++){
            dist[i][j] = 1e12;
        }
    }
    func();
    ll ans = 1e12;
    for(int i = 0 ; i <= k; i++){
        ans =min(ans, dist[n][i]);
    }
    cout << ans <<'\n';
}

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc= 1;
	while(tc--) {
		solve();
	}
}