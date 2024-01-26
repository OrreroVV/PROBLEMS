#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 5010;

char g[N][N];

void work()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> g[i];
        }
        vector<PII>w;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == '*')
                {
                    w.push_back({ i, j });
                }
            }
        }
        vector<vector<int>>st(n, vector<int>(m, false));
        vector<vector<LL>>dist(n, vector<LL>(m, 2e9));
        queue<PII> q;
        for (auto k : w)
            {
                int i = k.first, j = k.second;
                q.push({ i, j });
                dist[i][j] = 0;
            }
        auto bfs = [&]()-> bool{
            static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
            while (q.size())
            {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#')continue;
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
            return false;
        };
        bfs();
        vector<LL>res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] != '#' && g[i][j] != '*')res.push_back(dist[i][j]);
            }
        }
        sort(res.begin(), res.end());
        if (res.size() < 2)
        {
            cout << -1 << endl;
        }
        else cout << res[0] + res[1] << endl;
    }
}

int main()
{
	//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}