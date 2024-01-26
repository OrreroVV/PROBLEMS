#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>>g(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == '-')g[i][j] = -1;
                else g[i][j] = str[j] - '0';
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (g[i][j] == g[j][i] && g[i][j] != -1)
                    {
                        flag = false;
                    }
                    if (g[i][j] == -1)
                    {
                        if (g[j][i] == -1)
                        {
                            g[i][j] = 1;
                            g[j][i] = 0;
                        }
                        else
                        {
                            g[i][j] = g[j][i] ^ 1;
                        }
                    }
                }
                else
                {
                    if (g[i][j] == -1)g[i][j] = 1;
                }
            }
        }
        if (flag)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cout << g[i][j];
            cout << '\n';
        }
        else cout << "impossible\n";
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