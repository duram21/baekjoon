#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,k,m;

int main() {
	cin >> n;
	
    ll a = -1;
    ll b = -1;
    cout << "? 1" << endl;

    cin >> a;
    cout << "? " << n << endl;
    cin >> b;

    if(a == 1 && !b){
        cout << "! -1" << endl;
    }
    else if(!a && b == 1){
        cout << "! 1" << endl;
    }
    else cout << "! 0" << endl;

}