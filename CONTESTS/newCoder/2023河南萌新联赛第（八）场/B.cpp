#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 500100;
int MOD = 1e9 + 7;

LL qmi(LL a, LL b)
{
	LL res = 1;
	while (b)
	{
		if (b & 1)res = res * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return res;
}
int a[N], b[N];

void add(int x[], int a, int b)
{
    x[a]++;
    x[b + 1]--;
}

void work()
{
    int n;
    cin >> n;
	
    for (int i = 1; i <= n; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (max(l1, l2) <= min(r1, r2))
        {
            add(a, max(l1, l2), min(r1, r2));
        }
        else if (r1 + 1 < l2) 
        {
            add(b, r1 + 1, l2 - 1);
        }
        if (1 <= min(l1, l2) - 1)
        {
            add(b, 1, min(l1, l2) - 1);
        }
        add(b, max(r1, r2) + 1, 500000);
    }
    
    LL res = 0;
    for (int i = 1; i <= 500000; i++)
    {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        if (!b[i])(res += qmi(2, a[i])) %= MOD;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t = 1;
    //cin >> t;
    while (t--)
    {
        work();
    }
	return 0;
}