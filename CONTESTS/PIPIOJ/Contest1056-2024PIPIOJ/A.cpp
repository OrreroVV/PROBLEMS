#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

vector<int>s(100010);

void work()
{
    int n;
    while (cin >> n)cout << s[n] << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	//cin >> t;
    for (int i = 1; i * 2 <= 100000; i++)s[i * 2] = 1;
    for (int i = 1; i * 3 <= 100000; i++)s[i * 3] = 1;
    for (int i = 1; i * 5 <= 100000; i++)s[i * 5] = 1;
    for (int i = 1; i <= 100000; i++)s[i] += s[i - 1];
	while (t--)
	{
		work();
	}
	return 0;
}