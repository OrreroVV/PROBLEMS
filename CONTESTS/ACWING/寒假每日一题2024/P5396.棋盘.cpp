#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 3010;

int b[N][N], s[N][N];
int n;

void insert(int x1, int y1, int x2, int y2, int c)//(x1, y1), (x2, y2) += c
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

void get()
{
    	for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + b[i][j];
}


void work()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2, 1);
    }
    get();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (s[i][j] & 1);
        }
        cout << endl;
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