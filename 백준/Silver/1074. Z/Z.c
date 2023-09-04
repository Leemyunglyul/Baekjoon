long long area(long long n, int r, int c)
{
	static sum = 0;
	int x = n / 2;
	if (c >= n / 2 && r >= n / 2)
	{
		sum += 3 * (n / 2)* (n / 2);
		c = c - n / 2;
		r = r - n / 2;
	}
	else if (c >= n / 2)
	{
		sum += (n / 2) * (n / 2);
		c = c - n / 2;
	}
	else if (r >= n / 2)
	{
		sum += (n / 2) * (n / 2)*2;
		r = r - n / 2;
	}
	n = n / 2;
	if (n == 1)
		return sum;
	else
		area(n, r, c);
}

int main()
{
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	double result;
	double x = 2;
	double y = n;
	result = pow(x, y);
	long long z = result;
	printf("%lld", area(z, r, c));
}