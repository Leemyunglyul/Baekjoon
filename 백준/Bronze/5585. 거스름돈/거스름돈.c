int main()
{
    int n, i;
    scanf("%d", &n);
    n = 1000-n;
    i = n / 500;
    n = n % 500;
    i += n/100;
    n = n % 100;
    i += n / 50;
    n = n % 50;
    i += n / 10;
    n = n % 10;
    i += n / 5;
    n = n % 5;
    i += n / 1;
    printf("%d", i);
    
}