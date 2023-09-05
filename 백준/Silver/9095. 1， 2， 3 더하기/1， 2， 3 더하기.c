int main()
{
	int i, j, n, x;
	scanf("%d", &n);
	int a[10] = {0};
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;
	for (i = 3; i <= 9; i++)
	{
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		printf("%d\n", a[x - 1]);
	}
}