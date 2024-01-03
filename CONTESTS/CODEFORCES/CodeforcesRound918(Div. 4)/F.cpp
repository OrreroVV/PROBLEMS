#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 200010;

int tr[N];
int n, m;
int cnt;
map<int, int>h;

inline int lowbit(int x)
{
	return x & -x;
}

void add(int k, int x)//k位置 += x
{
	for (int i = k; i <= m; i += lowbit(i))
		tr[i] += x;
}

inline int sum(int k)
{
	int res = 0;
	for (int i = k; i; i -= lowbit(i))
		res += tr[i];
	return res;
}

void work()
{
    cin >> n;
	cnt = 0;
	h.clear();
	vector<int>uni;
	vector<PII>seg;

	uni.push_back(n * 2);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		uni.push_back(l);
		seg.push_back(PII(r, l));
	}
	sort(uni.begin(), uni.end());
	sort(seg.begin(), seg.end());
	for (auto i : uni)
	{
		if (!h.count(i))h[i] = ++cnt;
	}
	m = cnt;
	for (int i = 1; i <= cnt; i++)tr[i] = 0;
	LL res = 0;
	for (int i = 0; i < n; i++)
	{
		int l = seg[i].second, r = seg[i].first;
		res += sum(m) - sum(h[l]);
		add(h[l], 1);
	}
	cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
	return 0;
}
