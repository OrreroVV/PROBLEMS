#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    vector<LL>s(n + 2);
    for (int i = n; i >= 1; i--)s[i] = s[i + 1] + a[i];

    LL res = 0, now = m;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            flag = true;
            if (s[i] >= now)
            {
                if (now != m)flag = false;
                res += m - now;
                now = m;
            }
        }
        else
        {
            if (!flag && now <= a[i] || flag && a[i] >= m)
            {
                cout << "NO\n";
                return;
            }
            if (now > a[i])now -= a[i];
            else
            {
                res += m - now;
                now = m - a[i];
            }
            flag = false;
        }
        //cout << now << " " << res << endl;
    }
    cout << res + n - 1 << endl;
    return;
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