int arr[1000][3];

int maX(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b<= c)
        return b;
    else
        return c;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        if (arr[i - 1][0] <= arr[i - 1][1])
            arr[i][2] += arr[i - 1][0];
        else
            arr[i][2] += arr[i - 1][1];
        if (arr[i - 1][1] <= arr[i - 1][2])
            arr[i][0] += arr[i - 1][1];
        else
            arr[i][0] += arr[i - 1][2];
        if (arr[i - 1][0] <= arr[i - 1][2])
            arr[i][1] += arr[i - 1][0];
        else
            arr[i][1] += arr[i - 1][2];
    }
    printf("%d", maX(arr[n - 1][0], arr[n - 1][1], arr[n - 1][2]));
}