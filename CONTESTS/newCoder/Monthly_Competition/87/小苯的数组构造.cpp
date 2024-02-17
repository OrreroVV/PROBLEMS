#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

/*
1 5 4 3 10
0 -2 -1 0 0
*/

void work()
{
    int n;
    cin >> n;
    vector<int>a(n);
    int mx = 1e9;
    int res = 0;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> a[i];
        if (mx <= a[i])
        {
            res = max(res, a[i] - mx);
        }
        mx = min(mx, a[i]);
    }

    int last = -1e9;
    vector<int>b(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        b[i] = -(a[i] - res < last ? a[i] - last : res);
        last = a[i] + b[i];
    }
    for (int i = 0; i < n; i++)cout << b[i] << " ";
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