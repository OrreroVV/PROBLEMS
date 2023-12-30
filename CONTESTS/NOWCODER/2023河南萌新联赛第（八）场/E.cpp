#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;
const double pi = acos(-1.0);

double getsin(int rad)
{
    return sin(1.0 * rad / 180 * pi);
}

double getcos(int rad)
{
    return cos(1.0 * rad / 180 * pi);
}

void work()
{
    int n;
    cin >> n;
    pair<double, double> a, b, c, d, e;
    double x = 0.309016994375, y = 0.951056516295;
    a = {(1 + x) * n, 0};
    d = {-(1 + x) * n, 0};
    e = {0, y * n};
    double t = (2 * x + 2) * n;
    b = {x * t, (n - t) * y};
    c = {-x * t, (n - t) * y};
    printf("A: %.2lf %.2lf\n", a.first, a.second);
    printf("B: %.2lf %.2lf\n", b.first, b.second);
    printf("C: %.2lf %.2lf\n", c.first, c.second);
    printf("D: %.2lf %.2lf\n", d.first, d.second);
    printf("E: %.2lf %.2lf\n", e.first, e.second);
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