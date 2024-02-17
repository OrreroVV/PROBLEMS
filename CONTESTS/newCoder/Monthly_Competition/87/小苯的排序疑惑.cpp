#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    int minx = 2e9, mx = 0;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minx = min(minx, a[i]);
        mx = max(mx, a[i]);
    }

    if (minx == a[0] || mx == a[n - 1])cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}