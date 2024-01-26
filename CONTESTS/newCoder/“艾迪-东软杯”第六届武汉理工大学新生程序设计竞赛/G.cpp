#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>>f(n + 1, vector<int>(10, 1e9));

    for (int i = 1; i <= 7; i++)f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        for (int x = 1; x <= 7; x++)
        {
            for (int y = 1; y <= 7; y++)
            {
                if (abs(x - y) <= k)
                {
                    f[i][x] = min(f[i][x], f[i - 1][y] + (t == x ? 0 : 1));
                }
            }
        }
    }
    int res = 1e9;
    for (int i = 1; i <= 7; i++)res = min(res, f[n][i]);
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