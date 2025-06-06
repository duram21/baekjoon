#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;

ll n, a, b, c, m, l, q, d;
vector<tuple<ll, ll, ll>>v;
map<ll, ll>dir;
ll ans = 1e12;
ll ans1 = -1;
ll ans2 = -1;

ll dist(tuple<ll, ll, ll>a, tuple<ll, ll, ll>b) {
	return (get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b)) + (get<1>(a) - get<1>(b)) * (get<1>(a) - get<1>(b));
}

void func(ll st, ll en) {
	if (en - st + 1 <= 3) {
		for (int i = st; i <= en; i++) {
			for (int j = i + 1; j <= en; j++) {
				if (dist(v[i], v[j]) < ans) {
					ans1 = get<2>(v[i]);
					ans2 = get<2>(v[j]);
					ans = min(ans, dist(v[i], v[j]));
				}
			}
		}
		return;
	}
	vector<tuple<ll,ll,ll>>tmp;
	ll mid = (st + en) / 2;
	func(st, mid - 1);
	func(mid + 1, en);
	for (int i = mid - 1; i >= st; i--) {
		if (dist(make_tuple(get<0>(v[mid]), 0LL, 0LL), make_tuple(get<0>(v[i]), 0LL, 0LL)) < ans) {
			tmp.push_back(v[i]);
		}
		else break;
	}
	tmp.push_back(v[mid]);
	for (int i = mid + 1; i <= en; i++) {
		if (dist(make_tuple(get<0>(v[mid]), 0LL, 0LL), make_tuple(get<0>(v[i]), 0LL, 0LL)) < ans) {
			tmp.push_back(v[i]);
		}
		else break;
	}

	sort(tmp.begin(), tmp.end(), [](tuple<ll, ll, ll>t1, tuple<ll, ll, ll>t2) {return get<1>(t1) < get<1>(t2); });

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			if (dist(make_tuple(get<1>(tmp[i]), 0LL, 0LL), make_tuple(get<1>(tmp[j]), 0LL, 0LL)) >= ans) break;
			if (dist(tmp[i], tmp[j]) < ans) {
				ans = min(ans, dist(tmp[i], tmp[j]));
				ans1 = get<2>(tmp[i]);
				ans2 = get<2>(tmp[j]);
			}
		}
	}
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		v.push_back(make_tuple(abs(a), abs(b), (ll)i));
		if (a >= 0 && b <= 0) {
			dir[i] = 3;
		}
		else if (a <= 0 && b >= 0) {
			dir[i] = 2;
		}
		else if (a <= 0 && b <= 0) {
			dir[i] = 4;
		}
		else dir[i] = 1;
	}
	
	sort(v.begin(), v.end());

	func(0, n - 1);
	if(dir[ans1] == 1){
	    dir[ans1] = 4;
	}
	else if(dir[ans1] == 2){
	    dir[ans1] = 3;
	}
	else if(dir[ans1] == 3){
	    dir[ans1] = 2;
	}
	else if(dir[ans1] == 4){
	    dir[ans1] = 1;
	}
	cout << ans1 << ' ' << dir[ans1] << ' ' << ans2 << ' ' << dir[ans2] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	//cin >> tc;
	while (tc--) {
		solve();
	}
}