#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    double res = 1e9;
    for (int i = 0; i < n; i++)
    {
        res = min(res, 1.0 * (a[i] + 1) / (i + 1));
    }
    printf("%.8lf\n", res);
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