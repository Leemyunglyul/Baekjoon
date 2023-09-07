long long a[100][10];

long long divide(long long num)
{
	return num % 1000000000;
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	a[0][0]=0;
	for(i=1;i<10;i++)
		a[0][i] = 1;
	for (i = 1; i < n; i++)
	{
		a[i][0] = a[i-1][1];
		for (j = 1; j < 9; j++)
			a[i][j] = divide(a[i - 1][j - 1] + a[i - 1][j + 1]);
		a[i][9] = a[i - 1][8];
	}
	long long sum = 0;
	for (i = 0; i < 10; i++)
		sum += a[n - 1][i];
	printf("%lld", divide(sum));
}