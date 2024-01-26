#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

struct Node
{
    int a, b;
    bool operator<(const Node& n) const
    {
        if (a == n.a)return b > n.b;
        return a < n.a;
    }
};

void work()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Node>> v(m + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> b >> a;
        v[b].push_back({ a, i + 1 });
    }
    for (int i = 1; i <= m; i++)
    {
        sort(v[i].rbegin(), v[i].rend());
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j].b << " ";
        }
        if (v[i].empty())cout << -1;
        cout << endl;
    }
    cout << endl;
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