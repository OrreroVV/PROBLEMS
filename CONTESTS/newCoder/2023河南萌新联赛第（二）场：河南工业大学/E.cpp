#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    vector<pair<LL, LL>>a;
    LL n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x)
        {
            a.push_back({ i - x , i - 1});
            a.push_back({ i + 1, i + x });
        }
    }

	stack<pair<LL, LL>> q;
	sort(a.begin(), a.end());

	q.push(a[0]);
	for (int i = 1; i < a.size(); i++)
	{
        // a[i].first <= q.top().second
		if (a[i].first + 1 <= q.top().second) q.top().second = max(q.top().second, a[i].second);
		else q.push(a[i]);
	}

    LL res = 0;
    while (q.size())
    {
        auto [l, r] = q.top();
        q.pop();
        r = min(r, n);
        l = max(1ll, l);
        if (l <= r)res += r - l + 1;
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