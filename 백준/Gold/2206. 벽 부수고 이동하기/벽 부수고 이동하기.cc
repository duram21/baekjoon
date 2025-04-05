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

int n, m;
int graph[1000][1000];
int visited[1000][1000][2];
string str;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(void)
{
    queue<pair<pair<int, int>, int>>q;
    q.push({ {0, 0}, 1 });
    visited[0][0][1] = 1;
    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if (a == n - 1 && b == m - 1)
        {
            return visited[a][b][c];
        }


        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (graph[nx][ny] == 1 && c == 1)
            {
                visited[nx][ny][c - 1] = visited[a][b][c] + 1;
                q.push({ {nx,ny}, c - 1 });
            }

            if (graph[nx][ny] == 0 && !visited[nx][ny][c])
            {
                visited[nx][ny][c] = visited[a][b][c] + 1;
                q.push({{ nx, ny }, c});
            }

            
        }
    }
    return -1;
}


int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            graph[i][j] = str[j] - '0';
    }

    cout << bfs() << '\n';
}