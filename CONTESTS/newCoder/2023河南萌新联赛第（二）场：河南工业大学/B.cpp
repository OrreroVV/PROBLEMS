#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

LL trie[N][26], cnt[N], idx;
void insert(int x, int val)
{
	int p = 0;
	for (int i = 31; i >= 0; i--)
	{
		int ch = x >> i & 1;
		if (!trie[p][ch])trie[p][ch] = ++idx;
		p = trie[p][ch];
        cnt[p] += val;
	}
}

LL reserch(int a, int b)// x， h
{
    int p = 0;
    LL res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int x = a >> i & 1, y = b >> i & 1;
        if (y)
        {
            p = trie[p][x ^ 1];
        }
        else
        {
            res += cnt[trie[p][x ^ 1]];
            p = trie[p][x];
        }
        if (!p)return res;
    }
    return res;
}

void work()
{
    int q, hp;
    cin >> q >> hp;

    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 0)
        {
            insert(x, 1);
        }
        else if (op == 1)
        {
            insert(x, -1);
        }
        else
        {
            int h;
            cin >> h;
            LL val = reserch(x, h);
            if (!val)hp--;
            cout << val << endl;
        }
    }
    cout << hp << endl;
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