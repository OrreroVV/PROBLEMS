#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    string a, b;
    cin >> a >> b;
    map<char, int>h;
    for (auto i : b)h[i]++;

    for (auto i : a)
    {
        if (!h.count(i))
        {
            cout << 0 << endl;
            return;
        }
    }

    if (a.size() == 1)
    {
        cout << 5 << endl;
    }
    else cout << 10 << endl;
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