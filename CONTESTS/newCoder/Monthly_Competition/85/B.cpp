#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    //x / 4  * 2 + = n -  max(0, x % 4 - 2)
    LL n;
    cin >> n;
    LL x = n / 2 * 4;
    while (x / 4 * 2 + max(0ll, x % 4 - 2) != n)x++;
    cout << x << endl;
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