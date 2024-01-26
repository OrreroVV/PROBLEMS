#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2000010;

void work()
{
    int n;
    cin >> n;
    vector<int>x(n + 1), a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)cin >> x[i];
    for (int i = 1; i < n; i++)cin >> a[i] >> b[i + 1];
    vector<vector<double>>f(n + 1, vector<double>(2, 0));

    f[1][0] = x[1];
    f[1][1] = x[1] + a[1] / 0.7; //到达a[i]
    for (int i = 2; i <= n; i++) 
    {
        f[i][0] = min(f[i - 1][0] + x[i] - x[i - 1], f[i - 1][1] + b[i] / 1.3);
        f[i][1] = min({ f[i - 1][0] + x[i] - x[i - 1] + a[i] / 0.7, f[i - 1][1] + (a[i] >= b[i] ? (a[i] - b[i]) / 0.7 : (b[i] - a[i]) / 1.3)});
    }
    printf("%.2lf\n", f[n][0]);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}