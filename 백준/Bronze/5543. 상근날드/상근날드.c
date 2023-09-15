int main()
{
	int n, min, i, min1;
	min = 3000;
	min1 = 3000;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &n);
		if (n < min)
			min = n;
	}
	for (i = 0; i < 2; i++)
	{
		scanf("%d", &n);
		if (n < min1)
			min1 = n;
	}
	printf("%d", min+min1-50);
}