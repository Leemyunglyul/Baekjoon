int main()
{
	char edit[600010];
	char spare[300010];
	int n, i;
	char cmd, input;
	scanf("%s", edit);
	int cursor = strlen(edit);
	int s_cursor = 300000;
	scanf("%d", &n);
	spare[s_cursor+1] = '\0';
	for (i = 0; i < n; i++)
	{
		while (getchar() != '\n');
		cmd = getchar();
		if (cmd == 'P')
		{
			getchar();
			input= getchar();
			edit[cursor++] = input;
			edit[cursor] = '\0';
		}
		else if (cmd == 'L' && cursor!=0)
		{
			spare[s_cursor--] = edit[--cursor];
			edit[cursor] = '\0';
		}
		else if (cmd == 'D' && s_cursor !=300000)
		{
			edit[cursor++] = spare[++s_cursor];
			spare[s_cursor] = '\0';
		}
		else if (cmd == 'B' && cursor != 0)
		{
			edit[--cursor] = '\0';
		}
		
	}
	printf("%s%s", edit, &spare[s_cursor+1]);
}