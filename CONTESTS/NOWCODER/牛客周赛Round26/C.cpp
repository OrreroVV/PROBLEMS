#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 3010;

int n, m;
int dist[N][N];
bool st[N][N];

void work()
{
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++)
			cin >> g[i][j];

	
	int dx[] = { 0, 1, 0 }, dy[] = { 1, 0, -1 };
	queue<PII>q;
	memset(dist, 0x3f, sizeof(dist));
	q.push({ 0, 0 });
	dist[0][0] = 0;
	st[0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
        q.pop();
        st[x][y] = false;
        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int val = g[x][y] == g[nx][ny] ? 1 : 2;
			if (dist[nx][ny] > dist[x][y] + val)
			{
				dist[nx][ny] = dist[x][y] + val;
                if (!st[nx][ny])
                {
                    st[nx][ny] = true;
                    q.push({ nx, ny });
                }
			}
        }
	}
	cout << dist[n - 1][m - 1] << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}