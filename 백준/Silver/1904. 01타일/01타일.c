int arr[1000001] = {0};

int w(int n)
{
    for (int i = 3; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2])%15746;
    return arr[n];
}

int main()
{
    int n;
    arr[1] = 1;
    arr[2] = 2;
    scanf("%d", &n);
    printf("%d", w(n));
}