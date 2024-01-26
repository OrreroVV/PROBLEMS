#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int>res(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool flag = true;
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] >= a[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res[i] = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)cout << res[i] << endl;
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