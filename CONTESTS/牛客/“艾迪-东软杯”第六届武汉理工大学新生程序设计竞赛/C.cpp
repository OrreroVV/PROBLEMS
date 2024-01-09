#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int n, m;

void work()
{
    cin >> n;
    vector<LL>a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];

    vector<vector<LL>>tr(62, vector<LL>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)a[i] = 0;
        for (int j = 0; j <= 60; j++)
        {
            int x = a[i] >> j & 1;
            tr[j][i] += x;
        }
    }
    
    for (int i = 0; i <= 60; i++)
        for (int j = 1; j <= n; j++)
        {
            tr[i][j] += tr[i][j - 1];
        }

    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        LL sum = 0;
        for (int j = 0; j <= 60; j++)
        {
            if (tr[j][r] - tr[j][l - 1])sum += 1ll << j;
        }
        cout << sum << endl;
    }
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