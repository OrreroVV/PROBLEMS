#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2000010;

void work()
{
    LL n, d;
    cin >> n >> d;
    vector<LL> v(n), a(n), s(n + 1);
    for (int i = 0; i < n - 1; i++) cin >> v[i];
    for (auto &i : a)cin >> i;

    for (int i = 2; i <= n; i++)
    {
        s[i] = s[i - 1] + v[i - 2];
        
    }

    LL res = 0;
    LL mn = 1e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum < s[i + 1])
        {
            LL oil = (s[i + 1] - sum + d - 1) / d;
            sum += oil * d;
            res += mn * oil;
        }

        mn = min(mn, a[i]);
        //cout << sum << " " << mn << " " << res << endl;
    }
    cout << res << endl;
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