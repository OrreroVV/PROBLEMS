#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    double sum;
    int n;
    cin >> n;
    vector<pair<double, double>>v;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        v.push_back({ a, b});
        sum += a;
    }
    double res = 0;
    for (auto[a, b] : v)
    {
        res += a * b / sum;
    }
    printf("%.6lf\n", res);
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