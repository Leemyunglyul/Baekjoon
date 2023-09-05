long long gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a % b);
}

int main()
{
	int i, n, M, N, X, Y, jud;
	long long j, L, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &M, &N, &X, &Y);
		if (M == N)
		{
			if (X == Y)
				printf("%d\n", X);
			else
				printf("-1\n");
			continue;
		}
		if (M > N)
			L = M * N / gcd(M, N);
		else if (M < N)
			L = M * N / gcd(N, M);
		for (j = 0; M * j + X - Y <= L; j++)
		{
			if ((M * j + X - Y) % N == 0)
			{
				printf("%lld\n", M * j + X);
				break;
			}
		}
		if (M * j + X - Y > L)
			printf("-1\n");
	}
}