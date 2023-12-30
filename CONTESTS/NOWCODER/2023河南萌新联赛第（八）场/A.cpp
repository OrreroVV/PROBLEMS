#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int p[N];
LL val[N];

int find(int x)
{
	if (p[x] != x)return p[x] = find(p[x]);
	return p[x];
}

void work()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];

    for (int i = 1; i <= n; i++) val[i] = a[i];
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int pa = find(u), pb = find(v);
        if (b[u] == b[v] && pa != pb)
        {
            p[pb] = pa;
            val[pa] += val[pb];
            val[pb] = 0;
        }
    }
    vector<bool>st(n + 1);
    vector<LL>res;
    for (int i = 1; i <= n; i++)
    {
        int pi = find(i);
        if (b[i] == 1 && !st[pi])
        {
            st[pi] = true;
            res.push_back(val[pi]);
        }
    }

    sort(res.rbegin(), res.rend());
    LL ans = 0;
    for (int i = 0; i < max(1, min(k, (int)res.size())); i++)
    {
        ans += res[i];
    }
    cout << ans << endl;
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