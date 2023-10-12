#include <bits/stdc++.h>
using namespace std;

int n, d[50] = { 0, 1 };

int fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (d[n] != 0) return d[n];

	d[n] = fibo(n - 2) + fibo(n - 1);
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int ans = fibo(n);
	cout << ans;
}