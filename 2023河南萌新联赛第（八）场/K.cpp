#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 200010;

bool st[N];
int cnt = 0;
vector<int>prime;

void primes(int n = 1000000)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            prime.push_back(i);
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
    
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
	return 0;
}
