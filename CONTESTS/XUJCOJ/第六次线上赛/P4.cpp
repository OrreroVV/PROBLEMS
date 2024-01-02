#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>PII;
typedef long long LL;

const int N = 3;

LL n, m = 100000000003;

void mul(int c[], int a[], int b[][N])
{
	int temp[N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m;

	memcpy(c, temp, sizeof(temp));
}

void mul(int c[][N], int a[][N], int b[][N])
{
	int temp[N][N] = { 0 };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % m;

	memcpy(c, temp, sizeof(temp));
}

LL qmul()
{
	int f1[N] = { 1, 2, 1 };
	int a[N][N] = {
	   {3, -2, 0},
	   {0, 1, 0},
	   {0, 0, 1}
	};

	while (n)
	{
		if (n & 1) mul(f1, f1, a);
		mul(a, a, a);
		n >>= 1;
	}

	return f1[0];
}

int main()
{
    m = 100000000003;
	cin >> n;
	n--;
	cout << qmul() << endl;
	return 0;
}