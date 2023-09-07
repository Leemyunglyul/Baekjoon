long long a[100000][3];

long long divide(long long num)
{
	return num % 1000000009;
}

int main()
{
	int n, i, x;
	scanf("%d", &n);
	a[0][0] = 1;
	a[0][1] = 0;
	a[0][2] = 0;
	a[1][0] = 0;
	a[1][1] = 1;
	a[1][2] = 0;
	a[2][0] = 1;
	a[2][1] = 1;
	a[2][2] = 1;
	for (i = 3; i < 100000; i++)
	{
		a[i][0] = divide(a[i - 1][1] + a[i - 1][2]);
		a[i][1] = divide(a[i - 2][0] + a[i - 2][2]);
		a[i][2] = divide(a[i - 3][0] + a[i - 3][1]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("%lld\n", (a[x - 1][0] + a[x - 1][1] + a[x - 1][2]) % 1000000009);
	}
}