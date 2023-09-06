int Max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[301];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int a[301];
    a[0] = arr[0];
    a[1] = arr[0]+arr[1];
    a[2] = Max(a[0]+arr[2], arr[1]+arr[2]);
    for (i = 3; i < n; i++)
        a[i] = Max(a[i - 2] + arr[i], a[i - 3] + arr[i - 1] + arr[i]);
    printf("%d", a[n-1]);
}