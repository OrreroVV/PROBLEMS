#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2000010;

void work()
{
    LL n;
    cin >> n;
    int cnt = 0;
    for (LL i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)cnt++;
    cout << cnt << endl;
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