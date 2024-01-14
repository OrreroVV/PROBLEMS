#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    int temp;
    cin >> n;
    temp = n;
    int x = 0, y = 0;
    while (n)
    {
        y++;
        x += (n % 2 == 0);
        n /= 2;
    }
    LL res = 0;
    y--;
    res = 1;
    for (int i = 0; i < x; i++)
    {
        res = res * 2 + 0;
    }
    for (int i = 0; i < y - x; i++)res = res * 2 + 1;
    cout << temp - res << endl;
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