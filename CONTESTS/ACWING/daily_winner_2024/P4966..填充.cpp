#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    string str;
    cin >> str;
    int res = 0;
    int last = -1;// -1, 0, 1, 2
    for (int i = 0; i < str.size(); i++)
    {
        int x = str[i] - '0';
        if (last == x)
        {
            res++;
            last = -1;
        }
        else if (str[i] == '?')
        {
            if (last != -1)
            {
                res++;
                last = -1;
            }
            else
            {
                last = 2;
            }
        }
        else
        {
            if (last == 2)
            {
                res++;
                last = -1;
            }
            else
            {
                last = str[i] == '?' ? 2 : x;
            }
        }
    }
    cout << res << endl;
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