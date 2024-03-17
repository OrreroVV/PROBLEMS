#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const LL N = 2000010;

void work()
{
    map<int, string>h;

    int n, m;
    cin >> n >> m;
    int cnt = 0, sum = 0;
    while (m--)
    {
        int a;
        string b;
        cin >> a >> b;
        if (h.count(a))
        {
            if (h[a] != "AC")
            {
                if (b != "AC")sum++;
                else cnt++;
                h[a] = b;
            }
        }
        else
        {
            if (b == "AC")cnt++;
            else sum++;
            h[a] = b;
        }
    }
    cout << cnt << " " << sum << endl;
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