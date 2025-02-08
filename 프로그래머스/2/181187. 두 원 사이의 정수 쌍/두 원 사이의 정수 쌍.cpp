#include <string>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

long long solution(int r1, int r2) {
    
    long long answer = 0;
    answer += (r2 - r1 + 1) * 2;
    ll ans = 0;
    for(ll i = 1; i <= r2 ; i++){
        long long t1 = floor(sqrt((ll)r2 * r2 - i * i));
        if(i >= r1){
            ans += (t1) * 2 + 1;
            continue;
        }
        long long t2 = ceil(sqrt((ll)r1 * r1 -  i * i));
        ans += ((t1) - (t2) + 1) * 2;
    }
    answer += ans * 2;
    return answer;
}