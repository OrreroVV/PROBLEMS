#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 100, MOD = 1e9 + 7;

LL f[2][4][4][2];

LL qmi(LL a, LL b)
{
	LL res = 1;
	while (b)
	{
		if (b & 1)res = res * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return res;
}

void work()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            f[2 & 1][i][j][0] = 1;

    for (int i = 0; i < 3; i++)
        f[2 & 1][i][3][0] = f[2 & 1][3][i][0] = 23;
    f[2 & 1][3][3][0] = 23 * 23;

    for (int i = 3; i <= n; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            for (int x = 0; x < 4; x++)
            {
                for (int y =  0; y < 4; y++)
                {
                    LL val = 1;
                    if (y == 3)val = 23;
                    if (k == 0 && x == 1 && y == 2)
                    {
                        f[i & 1][x][y][1] += f[i - 1 & 1][k][x][0];
                    }
                    else
                    {
                        f[i & 1][x][y][1] += f[i - 1 & 1][k][x][1] * val;
                        f[i & 1][x][y][0] += f[i - 1 & 1][k][x][0] * val;
                    }
                    f[i & 1][x][y][1] %= MOD;
                    f[i & 1][x][y][0] %= MOD;
                }
            }
        }
    }
    LL res = 0;
    for (int i = 0; i < 4; i++)
        for (int j  = 0; j < 4; j++)
            {
                res += f[n & 1][i][j][0] + f[n & 1][i][j][1];
                //cout << char(i + 'A') << " " << char(j + 'A') << " " << f[n][i][j][0] << " " << f[n][i][j][1] << endl;
            }
    //cout << res << " " << qmi(26, n) << endl;
    cout << ((qmi(26, n) - res) % MOD + MOD) % MOD << endl;
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