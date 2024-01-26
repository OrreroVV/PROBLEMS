#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, p;
    cin >> n >> p;
    vector<LL>a(n);
    for (auto & i : a)cin >> i;

    auto check = [&](LL mid) -> LL{
        LL res = 0;
        for (int i = 0; i < n; i++)
        {
            res += max(0ll, a[i] - mid) * 2;
        }
        return res;
    };

    LL l = -1, r = 2e9;
    while (l < r)
    {
        LL mid = l + r + 1 >> 1;
        if (check(mid) >= p)l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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