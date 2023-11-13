int main()
{
	int n, i, x, j;
	scanf("%d", &n);
	int first = 1000;
	int last = 999+n;
	int arr[1000], deck[3000];
	for (i = 0;i < n; i++)
		scanf("%d", &arr[i]);    //터뜨릴 거
	for (i = 1000; i < 1000+n; i++)
		deck[i] = i-999;    //몇 번째 순서에 있는지
	while(last-first>0)
	{
		printf("%d ", deck[1000]);
		x = arr[deck[first]-1] %(last-first);
		if (x==0)
			x = arr[deck[first]-1];
		first++;
		if (x < 0)
		{
			for (j = -x; j >0; j--)
				deck[--first] = deck[last--];
			for (j = last; j >= first; j--)
				deck[j-first + 1000] = deck[j];
		}
		else
		{
			for (j = x; j >1; j--)
				deck[++last] = deck[first++];
			for (j = first; j <= last; j++)
				deck[j - first + 1000] = deck[j];
		}
		last = 1000 + last - first;
		first = 1000;

	}
	printf("%d", deck[1000]);
}