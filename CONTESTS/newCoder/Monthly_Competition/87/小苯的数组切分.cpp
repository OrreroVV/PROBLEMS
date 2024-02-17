#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    LL res = 0;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];

    vector<int>l(n + 1, 0);
    for (int i = 1; i < n - 1; i++)
    {
        l[i] = l[i - 1] ^ a[i];
    }
    int x = 0;
    /*
    [1, i - 1]
    [i, n - 1]
    [n, n]
    */
    for (int i = n - 1; i >= 1; i--)
    {
        x |= a[i];
        LL temp = 0;
        temp += l[i - 1];
        temp += x;
        res = max(res, temp);
    }
    res += a[n];
    cout << res << endl;
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