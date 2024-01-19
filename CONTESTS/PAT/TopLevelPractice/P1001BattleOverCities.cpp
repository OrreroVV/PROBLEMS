#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int n, m;
int p[N];
int d[N];

struct edge{
    int a, b, w, st;
    bool operator<(const edge &W)const
    {
        return w < W.w;
    }
}edge[N];

int find(int u)
{
    if(p[u]!=u) p[u] = find(p[u]);
    return p[u];
}

void kruskal()
{
	for (int i = 0; i < N; i++)p[i] = i;
	sort(edge, edge + m);
	int cnt = 0;

	vector<bool>st(n + 1, false);
	for (int i = 0; i < n; i++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w, ST = edge[i].st;
		int pa = find(a), pb = find(b);
		if (ST == 1)
		{
			st[a] = st[b] = true;
			if (pa != pb)
			{
				p[pa] = pb;
				cnt++;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w, st = edge[i].st;
		cout << a << " " << b << " " << w << " " << st << endl;
		int pa = find(a), pb = find(b);
		if (st == 1)continue;
		if (pa != pb)
		{
			res += w;
			p[pa] = pb;
			cnt++;
		}
	}
	cout << cnt << ' ' << res << endl;
}

void work()
{
    cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b, w, st;
		cin >> a >> b >> w >> st;
		d[b]++;
		d[a]++;
		edge[i] = { a, b, w, st };
	}
	kruskal();
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