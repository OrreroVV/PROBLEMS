#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    stack<char>l, r;
    int idx = str.find('I');

    for (int i = 0; i < idx; i++)l.push(str[i]);
    for (int i = n - 1; i > idx; i--)r.push(str[i]);

    while (m--)
    {
        string op;
        cin >> op;
        if (op == "backspace")
        {
            if (l.size())
            {
                if (l.top() == '(' && r.size() && r.top() == ')')
                {
                    l.pop();
                    r.pop();
                }
                else l.pop();
            }
        }
        else if (op == "delete")
        {
            if (r.size())
            {
                r.pop();
            }
        }
        else if (op == "->")
        {
            if (r.size())
            {
                auto t = r.top();
                r.pop();
                l.push(t);
            }
        }
        else if (op == "<-")
        {
            if (l.size())
            {
                auto t = l.top();
                l.pop();
                r.push(t);
            }
        }
    }
    string res;
    while (l.size())
    {
        res = l.top() + res;
        l.pop();
    }
    res += 'I';
    while (r.size())
    {
        res += r.top();
        r.pop();
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