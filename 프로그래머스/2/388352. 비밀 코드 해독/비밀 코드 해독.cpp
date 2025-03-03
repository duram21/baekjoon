#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    ll m = q.size();
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                for(int e = k + 1;  e <= n ;e ++){
                    for(int w = e + 1; w <= n; w++){
                        bool flag = 1;
                        for(int a = 0; a < m; a++){
                           ll cnt = 0;
                            for(auto cur : q[a]){
                                if(cur == i || cur == j || cur == k || cur == e || cur == w) cnt++;
                            }
                            if(cnt != ans[a]) flag= 0;
                        }
                        if(flag )answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}