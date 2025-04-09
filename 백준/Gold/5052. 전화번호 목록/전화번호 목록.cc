#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>


using namespace std;
using ll = long long;

int test_case;
int n;


bool fun(vector<string>v)
{
    bool ans = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1].substr(0, v[i].size()))
            return false;
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        cin >> n;
        vector<string>vec;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            vec.push_back(str);

        }
        sort(vec.begin(), vec.end());
        bool chk = fun(vec);
        if (chk) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}