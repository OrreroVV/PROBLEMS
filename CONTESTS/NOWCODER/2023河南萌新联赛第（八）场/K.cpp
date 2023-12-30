#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

bool st[N];
int cnt;
int prime[N];
int s[N];

void primes(int n = 1000000)
{
    st[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; prime[j] <= n / i; j++)
        {
            int t = prime[j] * i;
            st[t] = true;
            if (!(i % prime[j]))
            {
                break;
            }
        }
    }
}

void work()
{
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    cin >> t;
    primes();
    for (int i = 1; i <= 1e6; i++)
    {
        if (!st[i])s[i] += s[i - 1] + 1;
        else s[i] += s[i - 1];
    }
    while (t--)
    {
        work();
    }
	return 0;
}
