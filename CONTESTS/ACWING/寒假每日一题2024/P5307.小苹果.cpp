#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
	cin >> n;

	int cnt = 0;
	int res = 0;
	int temp = n;
	while (n > 0)
	{
		cnt++;
		//cout << cnt << " " << n << endl;
		if (n % 3 == 1 && !res)
		{
			res = cnt;
			
		}
		n -= (n + 2) / 3;
	}

	cout << cnt << " " << res << endl;
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