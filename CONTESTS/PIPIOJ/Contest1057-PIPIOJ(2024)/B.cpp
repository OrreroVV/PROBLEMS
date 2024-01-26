#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

void work()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>>a(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j  = 0; j < n; j++)
                cin >> a[i][j];

        
        vector<vector<bool>>st(n, vector<bool>(n, false));

        int x = 0;// 右下左上 0123
        int i = 0, j = 0;
        int cnt = 0;
        int tt = 5;
        while (true)
        {
            
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