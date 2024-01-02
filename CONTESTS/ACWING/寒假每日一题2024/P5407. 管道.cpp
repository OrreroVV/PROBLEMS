#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

vector<int>l, s;
int n, len;

bool check(int mid)
{
    vector<PII>seg;
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= mid)seg.push_back({ l[i] - (mid - s[i]), l[i] + (mid - s[i]) });
    }
    stack<PII> q;
	sort(seg.begin(), seg.end());

	q.push(seg[0]);
	for (int i = 1; i < seg.size(); i++)
	{
		if (seg[i].first <= q.top().second) q.top().second = max(q.top().second, seg[i].second);
		else q.push(seg[i]);
	}
    int last = len;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        //cout << t.first << " " << t.second << endl;
        if (t.second < last)return false;
        last = t.first - 1;
    }
    return true;
}

void work()
{
    cin >> n >> len;
    l.assign(n, 0);
    s.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> s[i];
    }

    int L = 0, R = 1e9;
    while (L < R)
    {
        int mid = L + R >> 1;
        if (check(mid))R = mid;
        else L = mid + 1;
    }
    cout << L << endl;
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