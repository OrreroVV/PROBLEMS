#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    string str;
    cin >> str;
    if (str.size() <= 3)
    {
        cout << "No" << endl;
        return;
    }
    map<char, int>h;
    for (auto i : str)h[i]++;

    int x = 0, y = 0;
    for (auto [k, v] : h)
    {
        if (v >= 2)x++;
        else if (v == 1)y++;
    }
    bool flag = false;
    if (y > 4)flag = false;
    if (y == 4 && !x)flag = true;
    if ((y == 0 && (x == 2 || x == 3 || x == 4)))flag = true;
    if ((y == 1 && (x == 2 || x == 3)))flag = true;
    
    if (y == 2 && (x == 1 || x == 2))flag = true;
    
    if ((y == 3 && (x == 1)))flag = true;
    
    cout << ((flag) ? "Yes" : "No") << endl;
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