#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[101];
vector<int> vec[101];

int tmp[101];

bool func(int val) {
	memset(tmp, 0, sizeof(tmp));
	tmp[N] = val;
	for (int i = N; i > 0; i--) {
		int mn = min(arr[i], tmp[i]);
		tmp[i] -= mn;
		if (tmp[i] && (!vec[i].empty())) {
			for (auto n : vec[i]) tmp[n] = min(tmp[n] + tmp[i], 1000000007);
			tmp[i] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (tmp[i]) return 0;
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	int K; cin >> K;
	while (K--) {
		int L, M; cin >> L >> M;
		while (M--) {
			int x; cin >> x;
			if (L <= N) vec[L].emplace_back(x);
		}
	}

	int L = 0, R = 1000000;
	while (L < R) {
		int mid = (L + R) / 2 + 1;
		if (func(mid)) {
			L = mid;
		}
		else {
			R = mid - 1;
		}
	}

    
    
    
    
    
    
    
    
	cout << L;
}