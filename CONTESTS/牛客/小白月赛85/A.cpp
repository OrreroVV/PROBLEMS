#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    string str;
    int n;
    cin >> n >> str;
    map<char, int>h;
    for (auto i : str)h[i]++;

    int res = min({ h['A'], h['C'] / 2, h['E'], h['P'], h['T'] });
    cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	t = 1;
	cin >> t;
	while (t--)
	{
		work();
	}
	return 0;
}