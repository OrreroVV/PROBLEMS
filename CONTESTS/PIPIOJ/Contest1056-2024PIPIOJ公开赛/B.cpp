#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;
const double pi = acos(-1.0);

vector<int>s(100010);

void work()
{
    int r, k;
    while (cin >> r >> k)
    {
        double res = 1.0 * k / 2 * r * r * sin(2 * pi / k);
        printf("%.3lf\n", res);
    }
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