#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int n;
vector<LL>get(vector<LL> a, vector<LL> b, vector<LL> c)
{
	vector<LL> res(n, 0);
	for (int i = 0; i < n; i++)
	{
		res[i] = a[i] - b[i] - c[i];
	}
	sort(res.begin(), res.end());
	return res;
}

LL get(vector<LL>a)
{
	LL res = -1;
	
	LL l = 0, r = 0;
	LL sum = 0;
	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cout << endl;
	while (l < n)
	{
		while (sum <= 0 && r < n)
		{
			sum += a[r++];
		}
		cout << l << " " << r << " " << sum << endl;
		if (sum > 0)res = max(res, r - l);
		sum -= a[l++];
	}

	return res;
}

void work()
{
    cin >> n;
    vector<LL>a(n), b(n), c(n);
    for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	for (int i = 0; i < n; i++)cin >> c[i];

	LL res = -1;
    auto t1 = get(a, b, c);
    res = max(res, get(t1));
	auto t2 = get(b, a, c);
	res = max(res, get(t2));
	auto t3 = get(c, a, b);
	res = max(res, get(t3));
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