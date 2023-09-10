int arr[100001] = {0};
int weight[100];
int value[100];

int main()
{
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &value[i]);
    if (arr[weight[0]] < value[0] && weight[0]<=k)
        arr[weight[0]] = value[0];
    for (i = 1; i < n; i++)
    {
        if (weight[i] > k)
            continue;
        for (j = k; j >=1; j--)
        {
            if (arr[j] != 0 && weight[i] + j<=k)
            {
                if (arr[weight[i] + j] < arr[j] + value[i])
                    arr[weight[i] + j] = arr[j] + value[i];
            }
        }
        if (arr[weight[i]] < value[i])
            arr[weight[i]] = value[i];
    }
    int max = arr[1];
    for (i = 2; i <= k; i++)
        if (max < arr[i])
            max = arr[i];
    printf("%d", max);
}