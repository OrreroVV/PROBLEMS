#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<LL>a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<LL>high(n + 1);
    for (int i = 1; i <= n; i++)cin >> high[i];

    vector<LL>f(n + 1);

    int last = 1;
    int lastsum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (high[i] != high[i - 1])
        {
            f[i] = a[i] + f[i - 1];
        }
        else
        {
            lastsum++;
            int l = i - k + 1;
            if (last < l)f[i] = s[i] - s[l - 1];
            else f[i] = s[i] - s[last] + f[last];
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << f[x] << endl;
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