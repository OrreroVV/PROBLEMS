#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010, MOD = 998244353;

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

LL mod(LL x)
{
    return (x % MOD + MOD) % MOD;
}

void work()
{
    LL a, b;
    cin >> a >> b;
    LL res = 0;
    res = qmi(a, b);
	for (int i = 2; i <= a / i; i++)
	{
		if (a % i == 0)
		{
			while (a % i == 0)a /= i;
			res *= 1 - qmi(i, MOD - 2);
            res = mod(res);
		}
	}
	if (a > 1)
	{
		res *= 1 - qmi(a, MOD - 2);
        res = mod(res);
	}
    cout << res << endl;
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