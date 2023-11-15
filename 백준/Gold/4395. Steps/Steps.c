long long arr[47000];

int main()
{
    long long a, n, least, x, y, i ,T;
    scanf("%d", &T);
    for (i = 0; i < 47000; i++)
        arr[i] = i * (i + 1);
    for (i = 0; i < T; i++)
    {
        scanf("%lld %lld", &x, &y);
        a = y - x;
        n = 0;
        if(x==y){ printf("0\n"); continue;
        }
        while (1)
        {
            if (a > arr[n] && a <= arr[n+1])
            {
                if (a > (n + 1) * (n + 1))
                {
                    least = 2*(n+1);
                    break;
                }
                else
                {
                    least = 2 * (n + 1)-1;
                    break;
                }
            }
            n++;
        }
        printf("%lld\n", least);
    }
}