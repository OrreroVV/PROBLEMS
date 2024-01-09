#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

struct Node
{
    int id1, id2;
    LL l, r;
};
void work()
{
    int n, m;
    cin >> n >> m;
    vector<LL>a(n + 1);
    LL mx = 0;
    LL sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx,  a[i]);
    }
    mx = max((sum + m - 1) / m, mx);

    vector<Node>res;
    int id = 1;
    LL last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mx >= last + a[i])//能放下id号机器
            {
                res.push_back({ i, id, last, last + a[i] });
            }
            else
            {
                res.push_back( { i, id, last, mx });
                a[i] -= mx - last;
                id++;
                last = 0;
                res.push_back({ i, id, last, last + a[i] });
            }
            last += a[i];
            if (last == mx)
            {
                id++;
                last = 0;
            }
    }
    cout << res.size() << endl;
    for (auto [a, b, c, d] : res)cout << a << " " << b << " " << c << " " << d << endl;

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