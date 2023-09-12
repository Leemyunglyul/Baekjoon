int main()
{
    char c[3];
    scanf("%s", c);
    float x;
    if (c[0] == 'A')
        x = 4.0;
    else if (c[0] == 'B')
        x = 3.0;
    else if (c[0] == 'C')
        x = 2.0;
    else if (c[0] == 'D')
        x = 1.0;
    else if (c[0] == 'F')
    {
        printf("0.0");
        return 0;
    }
    if (c[1] == '+')
        x += 0.3;
    else if (c[1] == '0')
        x = x;
    else
        x -= 0.3;
    printf("%.1f", x);
}