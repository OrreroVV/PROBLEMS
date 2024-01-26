#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    map<string, vector<string>>h;
    vector<string>str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = 0; j < str[i].size(); j++)
        {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z')temp += str[i][j];
        }
        h[temp].push_back(str[i]);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << h[s].size() << endl;
        for (int j = 0; j < h[s].size(); j++)
        {
            cout << h[s][j] << endl;
        }
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