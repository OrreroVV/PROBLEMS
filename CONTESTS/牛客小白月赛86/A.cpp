#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d > b * c)cout << "S" << endl;
    else cout << "Y" << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}