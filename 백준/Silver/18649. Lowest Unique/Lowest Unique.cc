#include <bits/stdc++.h>

using namespace std;

int n,k,m;

int main() {
	cin>>n>>k>>m;
	while(m--){
		int num;
		for(int i=1;i<=k;i++)cout<<i<<" ";
		cout<<endl;
		for(int i=0;i<n-k;i++)cin>>num;
	}
}