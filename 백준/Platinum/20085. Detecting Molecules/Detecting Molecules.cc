#include "molecules.h"
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    ll n = (ll)w.size();
	vector < pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		v.push_back({ w[i], i });
	}
	sort(v.begin(), v.end());
	ll lidx = 0;
	ll ridx = 0;
	ll sum = v[0].first;
	while (lidx < n && ridx < n) {
		if (sum >= l && sum <= u) {
			vector<int>ans;
			for (int i = lidx; i <= ridx; i++) {
				ans.push_back(v[i].second);
			}
			return ans;
		}
		if (ridx == lidx || (sum < l && ridx < n - 1)) {
			ridx++;
			sum += v[ridx].first;
		}
		else {
			sum -= v[lidx].first;
			lidx++;
		}
	}
	return std::vector<int>(0);
}
