int main()
{
	int i, len, stack[102], last;
	char word[102];
	while(1)
	{
		scanf("%[^\n]s", word);
		if (word[0] == '.')
			break;
		len = strlen(word);
		last = 0;
		for (i = 0; i < len-1; i++)
		{
			if (word[i] == '(')
				stack[last++] = 1;
			else if (word[i] == ')' && last > 0)
			{
				if (stack[last - 1] != 1)
					break;
				--last;
			}
			else if (word[i] == '[')
				stack[last++] = 2;
			else if (word[i] == ']' && last > 0)
			{
				if (stack[last - 1] != 2)
					break;
				--last;
			}
			else if (word[i] == ')' || word[i] == ']')
			{
				last = -1;
				break;
			}
		}
		if (last==0)
			printf("yes\n");
		else
			printf("no\n");
		getchar();
		
	}

}