int main() 
{
	int n, i;
	scanf("%d", &n);
	long long* distance=(long long*)malloc(sizeof(long long) * (n-1));
	long long* oil=(long long*)malloc(sizeof(long long) * n);
	long long sum = 0;
	for (i = 0; i < n - 1; i++)
		scanf("%lld", &distance[i]);
	for (i = 0; i < n; i++)
		scanf("%lld", &oil[i]);
	long long m=oil[0];
	for (i = 1; i < n; i++)
	{
		if (oil[i] < m)
			m = oil[i];
		else
			oil[i] = m;
	}
	sum = oil[0] * distance[0];
	m = oil[0];
	for (i = 1; i < n-1; i++)
	{
		if (m != oil[i])
			m = oil[i];
		sum += m * distance[i];	}
	printf("%lld", sum);
}