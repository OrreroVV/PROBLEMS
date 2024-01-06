#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 10010;

void work(vector<int> heights)
{
    int q[N];
    int hh = 0, tt = -1;
    int n = heights.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        // for (int i = hh; i <= tt; i++)
        //     cout << q[i] << " " << heights[q[i]] << endl;
        // cout << endl;
        if (hh <= tt)
        {
            int l = hh, r = tt;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (heights[q[mid]] >= heights[i]) l = mid;
                else r = mid - 1;
            }
            if (l == tt)res[i] = 1;
            else res[i] = tt - l + 1;
        }

        while (hh <= tt && heights[i] >= heights[q[tt]]) tt--;
        q[++tt] = i;
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        vector<int> a = {10, 6, 8, 5, 11, 9};
        work(a);
    }
    return 0;
}