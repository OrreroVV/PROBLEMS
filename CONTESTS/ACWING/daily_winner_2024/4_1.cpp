#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010, MOD = 1e9 + 7;

LL qmi(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

LL get(LL x)
{
    return x * (x + 1) % MOD * (2 * x + 1)  % MOD * qmi(6, MOD - 2) % MOD;
}

LL mod(int x)
{
    return (x % MOD + MOD) % MOD;
}

LL get(int x, int y)
{
    return mod(get(y) - get(x - 1));
}

void work()
{
    int n;
    cin >> n;
    LL res = 0;
    for (int i = 1, j = 1; i <= n; i = j + 1)
	{
		j = n / (n / i);//右边界
        //cout << i << " " << j  << " " << get(i, j) << endl;
		res += (n / i) * get(i, j);
        res %= MOD;
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