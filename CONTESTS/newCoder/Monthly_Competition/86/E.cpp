#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

LL f[N][20], ids;
vector<LL>s;
int n;

void init()
{
	ids = 19;
	for (int j = 0; j <= ids; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			if (!j)f[i][j] = s[i];
			else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

LL query(int l, int r)
{
	int len = r - l + 1;
	int k = log(len) / log(2);

	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void work()
{
    int m;
    cin >> n >> m;
    vector<LL>a(n + 1), b(n + 1);
    s.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    for (int i = 1; i <= n; i++)s[i] = s[i - 1] + b[i];

    init();

    LL sum = 0;
    LL res = -1e18;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (sum < m && j <= n)
        {
            sum += a[j++];
        }
        // j - 1 -> n
        //cout << sum << " " << i << " " << j << endl;
        if (sum >= m)res = max(res, query(j - 1, n) - s[i - 1]);

        sum -= a[i];
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