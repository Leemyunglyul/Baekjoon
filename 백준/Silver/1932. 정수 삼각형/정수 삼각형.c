int arr[500][500] = {0};

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j <= i; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0)
                arr[i][j] += arr[i - 1][j];
            else
            {
                if (arr[i - 1][j - 1] >= arr[i - 1][j])
                    arr[i][j] += arr[i - 1][j - 1];
                else
                    arr[i][j] += arr[i - 1][j];
            }
        }
    }
    int m = arr[n - 1][0];
    for (i = 1; i < n; i++)
    {
        if (arr[n - 1][i] > m)
            m = arr[n - 1][i];
    }
    printf("%d", m);
}