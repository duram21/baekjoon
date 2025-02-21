#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int ans = 0;
    sort(citations.rbegin(), citations.rend());
    int cur = 1;
    for(int i = 0 ; i < citations.size(); i++){
        if(citations[i] >= cur){
            ans = max(ans, cur);
        }
        cur++;
    }
    
    return ans;
}