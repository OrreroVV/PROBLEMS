#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;

const int N = 2000010;

class Solution {
public:
    bool check(int x)
    {
        if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0)return true;
        return false;
    }
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2)); 
        int d [] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (check(year))d[2] = 29;
        int res = 0;
        for (int i = 1; i < month; i++)res += d[i];
        res += day;
        return res;
    }
};

void work()
{
    
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