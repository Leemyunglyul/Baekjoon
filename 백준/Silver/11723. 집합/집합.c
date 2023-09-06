int main()
{
    int n, i, x;
    scanf("%d", &n);
    int arr[20] = { 0 };
    char word[7];
    for (i = 0; i < n; i++)
    {
        scanf("%s", word);
        if (strcmp(word, "add") == 0)
        {
            scanf("%d", &x);
            arr[x-1] = 1;
        }
        else if (strcmp(word, "remove") == 0)
        {
            scanf("%d", &x);
            arr[x - 1] = 0;
        }
        else if (strcmp(word, "check") == 0)
        {
            scanf("%d", &x);
            if (arr[x - 1] == 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else if (strcmp(word, "toggle") == 0)
        {
            scanf("%d", &x);
            if (arr[x - 1] == 0)
                arr[x - 1] = 1;
            else
                arr[x - 1] = 0;
        }
        else if (strcmp(word, "all") == 0)
        {
            for (x = 0; x < 20; x++)
                arr[x] = 1;
        }
        else if (strcmp(word, "empty") == 0)
        {
            for (x = 0; x < 20; x++)
                arr[x] = 0;
        }
    }
}