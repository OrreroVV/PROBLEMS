#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    vector<int>a[10];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    for (int i = 0; i < 10; i++)
    {
        sort(a[i].rbegin(), a[i].rend());
    }

    int x = n / 10;
    LL res = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i].size() < x)continue;
        else
        {
            for (int j = x; j < a[i].size(); j++)
            {
                res += a[i][j];
            }
        }
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