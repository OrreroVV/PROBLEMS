#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    vector<int>a;
    LL temp = 1;
    for (int i = 1; temp < 2e9; i++)
    {
        a.push_back(temp);
        temp *= 2;
    }
    int n;
    cin >> n;
    vector<int>x(n + 1);
    map<int, int>h;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        for (int j = 0; j < a.size(); j++)
        {
            int val = x[i] ^ a[j];
            if (!h.count(val))h[val] = j;
            else h[val] = min(h[val], j);
        }
    }
    int res = 2e9, res1 = 2e9, res2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h.count(x[i]))
            {
                int j = h[x[i]];
                if (res > j)
                {
                    res = j;
                    int x1 = x[i], x2 = x[i] ^ (1 << j);
                    if (x1 > x2)swap(x1, x2);
                    res1 = x1;
                    res2 = x2;
                }
                else if (res == j)
                {
                    
                    int x1 = x[i], x2 = x[i] ^ (1 << j);
                    if (x1 > x2)swap(x1, x2);
                    if (res1 > x1)
                    {
                        res1 = x1;
                        res2 = x2;
                    }
                }
            }
    }
    if (res == 2e9)
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
        cout << res1 << " " << res2 << "\n";
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