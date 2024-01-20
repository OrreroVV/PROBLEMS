#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 1), f(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])f[i] = f[i - 1] + 1;
        else f[i] = f[i - 1];
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (a[l] == a[l - 1])cout << f[r] - f[l - 1] + 1 << endl;
        else cout << f[r] - f[l - 1] << endl;
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