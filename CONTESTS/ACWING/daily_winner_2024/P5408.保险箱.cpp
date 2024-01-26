#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int mod(int x)
{
    return (x % 10 + 10) % 10;
}

void work()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>>f(n + 1, vector<int>(10));

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i <= n; i++)// 进位  不进位  退位 -> 0 1 2
    {
        int x = a[i] - '0', y = b[i] - '0';
        //x -> y
        // 不进位到进位 3 -> 2   0 -> 8
        f[i][0] = f[i - 1][1] + (x > y ? 10 - abs(x - y) : 10 + abs(x - y));


        //进位到进位
        // 9 -> 4   1 -> 4  4 -> 3
        if (x != 9)f[i][0] = min(f[i][0], f[i - 1][0] +((x + 1 > y) ? 10 - (x + 1 - y) : 10 + (x + 1 - y)));
        else f[i][0] = min(f[i][0], f[i - 1][0] + y);
        //退位到进位
        if (x != 0)f[i][0] = min(f[i][0], f[i - 1][2] + (x - 1 > y ? 10 - (x - 1 - y) : 10 + (x - 1 - y)));
        else f[i][0] = min(f[i][0], 9 - y);
        //不进位到不进位 进位到不进位  退位到不进位
        f[i][1] = min({ f[i - 1][1] + abs(x - y), f[i - 1][0] + abs(x + 1 - y), f[i - 1][2] + abs(x - 1 - y) });

        //进位到退位  3 -> 2  0 -> 8
        f[i][2] = f[i - 1][0] + abs(mod(x + 1) - 10 + y);
        //不进位到退位 3 -> 2 0 -> 8
        f[i][2] = min(f[i][2], f[i - 1][1] + abs(x - 10 + y));
        //退位到退位
        f[i][2] = min(f[i][2], f[i - 1][2] + abs(mod(x - 1) - 10 + y));
    }
    
    cout << min({ f[n][0], f[n][1], f[n][2] }) << endl;
}

/*
12000
11999
10999

12999
*/

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