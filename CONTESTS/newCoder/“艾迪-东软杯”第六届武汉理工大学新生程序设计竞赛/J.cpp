#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

struct Node{
    int t, x, y;  
};

void work()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<Node>v;
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back({ t, x, y });
    }

    reverse(v.begin(), v.end());
    set<int>row, col;

    vector<vector<bool>>st(n + 1, vector<bool>(m + 1, 0));

    static int dx[] = { 0, -1, 0, 1, 0 }, dy[] = { 0, 0, 1, 0, -1 };

    LL res = 0;
    for (auto[t, x, y] : v)
    {
        if (t == 1)
        {
            if (x == 1)row.insert(y);
            else col.insert(y);
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m)continue;
                if (!row.count(nx) && !col.count(ny))
                {
                    if (!st[nx][ny])res++;
                    st[nx][ny] = true;
                }
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