#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 1010;

int n, m;
char g[N][N];
map<int, int>mx, my;
vector<vector<bool>>st;

void bfs(int start, int ed)
{
    static int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

    queue<PII> q;
    q.push(make_pair(start, ed));
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        if (st[x][y])continue;
        st[x][y] = true;
        mx[x]++;
        my[y]++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            //cout << x << " " << y << " " << nx << " " << ny << endl;
            if (nx <= 0 || nx > n || ny <= 0 || ny > m || g[nx][ny] != '.') continue;
            q.push(make_pair(nx, ny));
        }
    }
}

void work()
{
    cin >> n >> m;
    st.assign(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++) cin >> g[i] + 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!st[i][j] && g[i][j] == '.')
            {
                mx.clear(), my.clear();
                bfs(i, j);
                //cout << cnt << " " << i << " " << j << " " << mx << " " << my << endl;
                bool flag = true;
                for (auto it = mx.begin(); it != mx.end(); it++)
                {
                    if ((*it).second != (*mx.begin()).second)flag = false;
                }
                for (auto it = my.begin(); it != my.end(); it++)
                {
                    if ((*it).second != (*my.begin()).second)flag = false;
                }
                res += flag;
            }
        }
    }
    cout << res << endl;
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