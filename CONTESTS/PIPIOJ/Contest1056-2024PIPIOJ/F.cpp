#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int q[N];

void work()
{
    int n, k;
    cin >> n >> k;

    vector<int>a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    int hh = 0, tt = -1;
    vector<int>res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (hh <= tt && q[hh] - i > k)hh++;
        while (hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        res[i] = q[hh] + 1;
    }
    for (auto i : res)cout << i << " ";
    cout << endl;
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