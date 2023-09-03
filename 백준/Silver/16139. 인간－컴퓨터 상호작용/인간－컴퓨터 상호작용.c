int main() 
{
    char word[2000];
    scanf("%s", word);
    int len=strlen(word);
    int i, j, x, n, y, z;
    long long** arr = (long long**)malloc(sizeof(long long*) * len);
    for (i = 0; i < len; i++)
        arr[i] = (long long*)malloc(sizeof(long long) * 26);
    for (i = 0; i < len; i++)
        for (j = 0; j < 26; j++)
            arr[i][j] = 0;
    x = word[0] - 97;
    arr[0][x]++;
    for (i = 1; i < len; i++)
    {
        x = word[i]-97;
        for (j = 0; j < 26; j++)
            arr[i][j] = arr[i-1][j];
        arr[i][x]++;
    }
    scanf("%d", &n);
    getchar();
    char w;
    for (i = 0; i < n; i++)
    {
        scanf("%c %d %d", &w, &x, &y);
        getchar();
        z = w - 97;
        if(x==0)
            printf("%lld\n", arr[y][z]);
        else
            printf("%lld\n", arr[y][z]- arr[x-1][z]);
    }
}