#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <functional>

using namespace std;
using ll = long long;

int n, m;
int memory[101];
int cost[101];
int dp[101][10001];
int ans = 987654321;

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (cost[i] <= j) {
				dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= m) {
				ans = min(ans, j);
			}
		}
	}
	cout << ans << '\n';
}
	