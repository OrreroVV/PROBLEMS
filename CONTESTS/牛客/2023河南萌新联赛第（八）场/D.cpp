#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int X, Y;
    cin >> X >> Y;
    int n;
    cin >> n;
    string str;
    cin >> str;

    int x = 0, y = 0, level = 0, ver = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'D')
        {
            y--;
            ver--;
        }
        else if (str[i] == 'U')
        {
            y++;
            ver++;
        }
        else if (str[i] == 'L')
        {
            x--;
            level--;
        }
        else if (str[i] == 'R')
        {
            x++;
            level++;
        }

        if (x == X && y == Y)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    if (level == 0 && ver == 0)
    {
        cout << "No" << endl;
        return;
    }

    if (level * X < 0)

    if (!level)
    {
        int ytimes = Y /
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