#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

int n;
vector<int>a;

bool check(LL mid)
{
    LL l1 = a[0] + mid;
    LL r1 = l1 + mid;
    //cout << l1 << " " << r1 << endl;
    if (r1 >= a.back())return true;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > r1)
        {
            LL l2 = a[i] + mid;
            LL r2 = l2 + mid;
            //cout << l2 << " " << r2 << endl;
            if (r2 >= a.back())return true;
            for (int j = i; j < a.size(); j++)
            {
                if (a[j] > r2)
                {
                    int l3 = a[j] + mid;
                    int r3 = l3 + mid;
                    //cout << l3 << " " << r3 << endl;
                    if (r3 >= a.back())return true;
                    return false;
                }
            }
        }
    }
    return false;
}

void work()
{
    cin >> n;
    a.assign(n, 0);
    for (auto& i : a)cin >> i;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    LL l = 0, r = 1e9;
    while (l < r)
    {
        LL mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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