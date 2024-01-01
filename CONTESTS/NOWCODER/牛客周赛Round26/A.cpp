#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, k;
    cin >> n >> k;
    map<int, int>h;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h[x % k]++;
    }
    int res = 0;
    for (auto[k, v] : h)
    {
        res = max(res, v);
    }
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