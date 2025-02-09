#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll>edges[20202];
ll visited[20202];

void bfs(ll x){
    queue<ll>q;
    q.push(1);
    visited[1] = 0;
    while(q.size()){
        ll a = q.front();
        q.pop();
        for(ll nxt : edges[a]){
            if(visited[nxt]) continue;
            visited[nxt] = visited[a] + 1;
            q.push(nxt);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    ll nn = edge.size();
    for(int i = 0 ; i < nn; i++){
        ll a=  edge[i][0];
        ll b= edge[i][1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs(1);
    ll mn = -1;
    for(int i = 1; i <= n; i++){
        mn = max(mn, visited[i]);
    }
    for(int i = 2; i <= n; i++){
        if(visited[i] == mn) answer++;
    }
    return answer;
}