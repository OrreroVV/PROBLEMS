#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;


void work()
{
    string s;
    cin >> s;
    vector<char>str;
    for (auto i : s)str.push_back(i);
    vector<char>last;
    while (true)
    {
        vector<char> temp;
        int n = str.size();
        vector<bool>st(n, 0);
        for (int i = 1; i < n - 1; i++)
        {
            if (str[i] == str[i - 1] && str[i] != str[i + 1])st[i] = st[i + 1] = true;
            if (str[i] != str[i - 1] && str[i] == str[i + 1])st[i] = st[i - 1] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (!st[i])temp.push_back(str[i]);
        }
        if (temp == last)break;
        last = str;
        str = temp;
    }
    if (last.empty())cout << "EMPTY\n";
    else
    {
        for (auto i : last)cout << i;
        cout << "\n";
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