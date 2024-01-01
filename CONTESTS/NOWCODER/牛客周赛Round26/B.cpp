#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    string str;
    cin >> str;
    string res;
    int x = 0, y = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int j = i;
        while (j < str.size() && str[j] == str[i])j++;
        if ((j - i) & 1)
        {
            res.push_back(str[i]);
            if (str[i] == '1')x++;
            else y++;
        }
        else 
        {
            if (str[i] == '1')
            {
                res.push_back('0');
                res.push_back('0');
            }
            else
            {
                res.push_back(str[i]), res.push_back(str[i]);
            }
        }
        i = j - 1;
    }

    if ((x & 1) && (y & 1))
    {
        cout << "No" << endl;
    }
    else cout << "Yes\n";
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