#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    vector<vector<int>> s(61, vector<int>(n + 1, 0));
    for (int i = 0; i <= 60; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            LL x = a[j];
            s[i][j] = s[i][j - 1];
            if (x >> i & 1)s[i][j]++;
        }
    }

    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        LL res = 0;
        for (int i = 0; i <= 60; i++)
        {
            if (s[i][r] - s[i][l - 1])
            {
                res += 1ll << i;
            }
        }
        cout << (x | res)<< endl;
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