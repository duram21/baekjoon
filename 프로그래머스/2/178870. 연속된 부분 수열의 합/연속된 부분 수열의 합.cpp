#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    ll cur =0;
    map<ll ,ll>m;
    ll a1 = 0;
    ll a2 = 0;
    ll gap = 1e9;
    m[0] = -1;
    for(int i = 0; i < sequence.size(); i++){
        cur += sequence[i];
        m[cur] = i;
        if(m.find(cur - k) != m.end()){
            if(i - m[cur-k] < gap){
                a1 = m[cur-k] + 1;
                a2 =  i;
                gap = a2 - a1 + 1;
            }
        }
    }
    answer.push_back(a1);
    answer.push_back(a2);
    return answer;
}