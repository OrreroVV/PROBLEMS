#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    int x2 = 0, x5 = 0;
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++)
    {
        LL x = 4 * i - 2, y = i + 1;
        while (x % 2 == 0)
        {
            x /= 2;
            x2++;
        }
        while (x % 5 == 0)
        {
            x /= 5;
            x5++;
        }
        while (y % 2 == 0)
        {
            y /= 2;
            x2--;
        }
        while (y % 5 == 0)
        {
            y /= 5;
            x5--;
        }
        res1 += x2, res2 += x5;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    cout << min(res1, res2) << endl;
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