#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool visited[1010101];
bool chk[1010101];
set<ll>s;
vector<ll>v[1010101];

void bfs(ll x){
    s.insert(x);
    queue<ll>q;
    q.push(x);
    visited[x] =1;
    while(q.size()){
        ll a= q.front();
        q.pop();
        
        for(auto nxt : v[a]){
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
            s.insert(nxt);
        }
    }
}


vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;
    ll hol = 0;
    ll rhol = 0;
    for(int i = 0; i < nodes.size() ;i++){
        ll a = nodes[i];
        chk[a] = 1;
    }
    
    for(int i = 0 ; i < edges.size(); i++){
        ll a = edges[i][0];
        ll b=  edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
        
        
    }
    for(int i = 1; i <= 1000000; i++){
        if(!chk[i]) continue;
        if(visited[i]) continue;
        s.clear();
        bfs(i);
        
        ll val1 = 0;
        ll val2 = 0;
        if(s.size() == 1){
            if(i % 2 == 0) rhol++;
            else hol++;
            continue;
        }
        for(auto cur : s){
            if(cur % 2 == 0){
                if(v[cur].size() % 2 == 0) val1++;
                else val2++;
            }
            else{
                if(v[cur].size() % 2)val1++;
                else val2++;
            }
        }
        if(val1 == 1){
            rhol++;
        }
        if(val2 == 1){
            hol++;
        }
        cout << val1 << ' ' << val2 << ' ' << i << '\n';
    }
    
    answer.push_back(rhol);
    answer.push_back(hol);
    
    return answer;
}