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
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.rbegin(), a.rend());

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)x += a[i];
        else y += a[i];
    }
    cout << (x < y ? "Alice" : "Bob") << endl;
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