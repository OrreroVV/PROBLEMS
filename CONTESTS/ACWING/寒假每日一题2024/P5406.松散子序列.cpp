#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

char str[N];

void work()
{
    cin >> str + 1;
    int n = strlen(str + 1);
    vector<LL>f(n + 1);
    LL mx = 0;
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        if (i >= 2)mx = max(mx, f[i - 2]);
        f[i] = max(f[i], mx + str[i] - 'a' + 1);
    }
    LL res = 0;
    for(int i = 1; i <= n; i++)res = max(res, f[i]);
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