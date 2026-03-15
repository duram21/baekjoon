#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, a, b;
	cin >> tc;
	while (tc--)
	{
		cin >> a >> b;
		cout << a + b<< '\n';
	}
}