int a[1000002];

int MIN(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else if (c <= a && c <= b)
		return c;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (i = 3; i < n; i++)
	{
		if ((i + 1) % 2 == 0 && (i + 1) % 3 == 0)
			a[i] = MIN(a[i - 1], a[(i + 1) / 2 - 1], a[(i + 1) / 3 - 1])+1;
		else if ((i + 1) % 2 == 0)
			a[i] = MIN(a[i - 1], a[i - 1], a[(i + 1) / 2 - 1])+1;
		else if ((i + 1) % 3 == 0)
			a[i] = MIN(a[i - 1], a[i - 1], a[(i + 1) / 3 - 1])+1;
		else
			a[i] = a[i - 1] + 1;
	}
	printf("%d", a[n - 1]);
}