#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;
using ll = long long;
ll dp[505050][2];
ll dart[66][2];


vector<int> solution(int target) {
    vector<int> answer;
    for(int i= 1; i <= 20; i++){
        dart[i][0] = 1;
        dart[i][1] = 1;
        dart[i * 2][0] = 1;
        dart[i * 3][0] = 1;
    }
    for(int i = 1; i <= 60; i++){
        if(dart[i][0] == 0){   
            dart[i][0] = 2;
            dart[i][1] = 1;
            if(i >= 51){
                dart[i][0] = 2;
                dart[i][1] = 2;
            }
        }
        
    }
    dart[50][0] = 1;
    dart[50][1] = 1;
    
    for(int i = 0 ; i <= target; i++){
        dp[i][0] = 1e9;
        dp[i][1] = 1e9;
    }
    dp[0][0] = 0;
    dp[0][1] =0;
    for(int i = 0; i <= target; i++){
        for(int j = 1; j <= 60;j ++){
            if(dp[i+j][0] > dp[i][0] + dart[j][0]){
                dp[i+j][0] = dp[i][0] + dart[j][0];
                dp[i+j][1] = dp[i][1] + dart[j][1];
            }
            else if(dp[i+j][0] == dp[i][0] + dart[j][0]){
                dp[i+j][1] = max(dp[i+j][1], dp[i][1] + dart[j][1]);
            }
        }
    }
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    return answer;
}