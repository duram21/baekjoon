#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tc, n, a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    bool flag = 1;
    ll cnt = 0;
    while(a < c && b < d){
        if(abs(b-a) > abs(d-c)) break;
      
        // possible  both odd
        if((d % 2) && (c % 2)){
            c--; d--;
            cnt++;
            continue;
        }
        // 짝짝
        // 2로 나누는게 가능
        if(d%2 == 0 && c %2 == 0 && d/2 >= b && c/2 >= a){
            if(abs(a - b) <= (abs(d/2 - c/2))){
                c /= 2; d /= 2;
                cnt++;
                continue;
            }
        }
        if(abs(b - a) == abs(d - c)){
            cnt += abs(c-a);
            d = b;
            c = a;
        } 
        break;
    }
    if(a == c && b == d) cout << cnt << '\n';
    else cout << -1 <<'\n';
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//cin >> tc;
	tc= 1;
	while(tc--) {
		solve();
	}
}